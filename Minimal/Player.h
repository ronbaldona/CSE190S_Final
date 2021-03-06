/* By Ronald Allan Baldonado
 * Player class derived from Node.h
 * Compatible with Scene Graph
 */
#pragma once
#ifndef _PLAYER_H_
#define _PLAYER_H_

#define GLFW_INCLUDE_GLEXT
#ifdef __APPLE__
#define GLFW_INCLUDE_GLCOREARB
#else
#include <GL/glew.h>
#endif
#include <GLFW/glfw3.h>
// Use of degrees is deprecated. Use radians instead.
#ifndef GLM_FORCE_RADIANS
#define GLM_FORCE_RADIANS
#endif
#include <glm/mat4x4.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <iostream>
#include <vector>

#include "Model.h"
#include "Bound.h"

class Player {
public:
	/* Public functions */
	Player();	// Default ctor
	/* ctor for player object
	 * head - ptr to 3D head object
	 * hand - ptr to 3D hand object
	 * sword - ptr to 3D sword object
	 * playerType - true = Player 1, false = Player 2
	 */
	Player(Model * head, Model * hand, Model * sword, bool playerType);
	~Player();	// Default dtor

	int getScore();
	// TODO: Add function to handle sword hits here

	/* Player render function
	 * shader - glsl shader to send vertex and other info to for gfx
	 * P - projection matrix
	 * V - view matrix
	 * handTransform - hand transformation matrix
	 * headTransform - head transformation matrix
	 */
	void drawPlayer(Shader shader, glm::mat4 P, glm::mat4 V, glm::mat4 handTransform, glm::mat4 headTransform);
	void drawPlayer(Shader shader, glm::mat4 P, glm::mat4 V, glm::mat4 hand_translate, glm::mat4 hand_rotate, glm::mat4 headTransform);
	void drawBoundingBox(Shader shader, glm::mat4 P, glm::mat4 V, glm::mat4 handTransform);

	float getSwordScaleFactor();
	void updateBoundingBox(glm::mat4 transform_mat);
	bool checkHit(Bound * toCompare);

private:
	/* Private Data */
	unsigned int score;
	unsigned int playerType;
	float sword_scale_factor;		// Contains sword scale factor
	std::vector<Model *> models;	// Will store pointers to head and hand(s)
	Bound * attack_box = NULL;		// Sword hitbox

	/* Private Functions */
	void initialize();	// Resize and rotate everything to the correct position
};

#endif
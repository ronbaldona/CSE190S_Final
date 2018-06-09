#pragma once
#ifndef _ENEMY_H_
#define _ENEMY_H_

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

class Enemy : public Node {
public:
	/* Public functions */
	Enemy();
	/* Enemy main constructor
	 * enemy_model - ptr to 3D model object
	 * strong - denotes whether enemy will get 1 or 3 HP
	 * scale_size - for scaling enemy to correct size
	 */
	Enemy(Model * enemy_model, bool strong, float scale_size);
	~Enemy();

	void spawnMonsters();
	bool wasHit();

	void draw(Shader shader, glm::mat4 P, glm::mat4 V, glm::mat4 C);
	void update();

private:
	/* Private Data */
	unsigned int enemyType;
	int hp;
	Model * enemy;
	Bound * hitbox;
};

#endif
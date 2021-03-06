/* By Ronald Allan Baldonado
 * Header class defining implementation of uniform sampled bezier curve
 * Particular implementation used for defining enemy path in game
 */
#pragma once
#ifndef CURVE_H
#define CURVE_H
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

#include <GLFW/glfw3.h>
#include <glm/mat4x4.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <vector>

#endif

class Curve {
private:
	/* Data */
	// Used in calculating points for the bezier curve
	glm::mat4 b_bez = {
		-1.0f, 3.0f, -3.0f, 1.0f,
		3.0f, -6.0f, 3.0f, 0.0f,
		-3.0f, 3.0f, 0.0f, 0.0f,
		1.0f, 0.0f, 0.0f, 0.0f
	};

	glm::mat4 g_bez;	// Column vectors make up control points
	glm::mat4 c_bez;	// Multiply g_bez by b_bez
	float num_samples;
	
	glm::mat4 toWorld;
	std::vector<glm::vec3> vertices;
	std::vector<unsigned int> indices;

	// These variables are needed for the shader program
	GLuint VBO, VAO, EBO;
	GLuint uProjection, uModelview;

	/* Private functions */
	// Initialize buffers for debug drawing the curve
	void init_buffers();
	// Calculates points on curve based on number of samples and fills vertices and indices
	void calc_pnts();
public:
	/* Public Functions*/
	Curve();
	/* Curve constructor. Default number of samples is 150
	 * control_pts - 4x4 matrix where each column defines a 4-vector for a bezier curve control point
	 */
	Curve(glm::mat4 control_pts);
	/* Curve constructor.
	 * control_pts - 4x4 matrix where each column defines a 4-vector for a bezier curve control point
	 * num_samples - Number of samples
	 */
	Curve(glm::mat4 control_pts, unsigned int num_samples);		// Pick your own number of samples by passing it in as num_samples
	~Curve();

	// Curve vertices getter method
	std::vector<glm::vec3> & getVertices();			
	/* Curve render function
	 * shaderProgram - glsl shader ID
	 * P - Projection matrix
	 * V - view matrix
	 */
	void draw(GLint shaderProgram, glm::mat4 P, glm::mat4 V);
};
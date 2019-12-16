#pragma once

#include "GL/glew.h"
#include <GLFW/glfw3.h>
#include <glm/vec3.hpp>

using namespace glm;

class Camera{
	public:
		static Camera& instance() { static Camera cam; return cam; }
		vec3 position;
		void initCamera(int width, int height);
		void updateCamera(int width, int height, float delta, GLFWwindow* window);
		vec3 getPosition();
};


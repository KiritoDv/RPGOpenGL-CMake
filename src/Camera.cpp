#include "Camera.h"

vec3 tmpPosition;

void Camera::initCamera(int width, int height) {
	int cW = position.x + width;
	int cH = position.y + height;
	glMatrixMode(GL_PROJECTION);
	glViewport(0, 0, width, height);
	glLoadIdentity();
	glOrtho(position.x, cW, cH, position.y, 0.0, 1.0);
}

void Camera::updateCamera(int width, int height, float delta, GLFWwindow* window) {

	float speed = delta;

	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
		Camera::position += vec3(0, -speed, 0);
	}
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
		Camera::position += vec3(0, speed, 0);
	}
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
		Camera::position += vec3(-speed, 0, 0);
	}
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
		Camera::position += vec3(speed, 0, 0);
	}

	tmpPosition = Camera::position;

	Camera::initCamera(width, height);
}

vec3 Camera::getPosition() {
	return tmpPosition;
}
#include "IDisplay.h"

#include <stb_image.h>

void IDisplay::initDisplay(int width, int height, GLFWwindow* window) {
	windowWidth = width;
	windowHeight = height;

	//Image i;	

	GLFWimage icons[1];
	icons[0].pixels = stbi_load("assets/icon512.png", &icons[0].width, &icons[0].height, 0, STBI_rgb_alpha);
	glfwSetWindowIcon(window, 1, icons);
	stbi_image_free(icons[0].pixels);

}

void IDisplay::resizeDisplay(int newWidth, int newHeight) {
	windowWidth = newWidth;
	windowHeight = newHeight;
}
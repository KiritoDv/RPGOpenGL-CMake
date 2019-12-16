#include "Game.h"

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/vec3.hpp>

#include "IDisplay.h"
#include "Color.h"
#include "Camera.h"

using namespace glm;

int width = 1280;
int height = 720;
bool fullscreen = false;

int main( void ) {

	//ShowWindow(GetConsoleWindow(), SW_HIDE);

	if (!glfwInit()) {
		fprintf(stderr, "Failed to start GLFW");
		return -1;
	}

	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);

	GLFWwindow* window = glfwCreateWindow(width, height, "RPGGame", NULL, NULL);

	if (!window) {
		fprintf(stderr, "Failed to create Window");
		glfwDestroyWindow(window);
		return -1;
	}

	glfwMakeContextCurrent(window);

	if (glewInit() != GLEW_OK) {
		fprintf(stderr, "Failed to start GLEW");
		return -1;
	}

	IDisplay::instance().initDisplay(width, height, window);
	Game g = Game::instance();
	Camera cam = Camera::instance();

	glfwSwapInterval(0);

	glfwSetFramebufferSizeCallback(window, [](GLFWwindow* window, int w, int h) {
		Camera::instance().updateCamera(w, h, 0.0f, window);

		IDisplay::instance().resizeDisplay(w, h);

		width = w;
		height = h;
	});

	cam.initCamera(width, height);

	glfwSetKeyCallback(window, [](GLFWwindow* window, int key, int scancode, int action, int mods) {

	});
	g.init();

	glfwSetInputMode(window, GLFW_STICKY_KEYS, GLFW_TRUE);

	int oldTimeSinceStart = 0;

	float previous = glfwGetTime();

	while (!glfwWindowShouldClose(window)) {
		float now = glfwGetTime();
		float delta = (now - previous) * 1000;
		previous = now;

		g.update();
		cam.updateCamera(width, height, delta, window);

		Color c(100, 149, 237, 255);
		glClearColor(c.r / 255.0f, c.g / 255.0f, c.b / 255.0f, c.a / 255.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glEnable(GL_TEXTURE_2D);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		g.draw();

		glDisable(GL_TEXTURE_2D);
		glEnable(GL_BLEND);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();

	return 0;
}
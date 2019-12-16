#pragma once

#include <GLFW/glfw3.h>

class IDisplay{
	public:
		static IDisplay& instance() { static IDisplay display; return display; }
		void initDisplay(int width, int height, GLFWwindow* window);
		void resizeDisplay(int newWidth, int newHeight);
		int windowWidth;
		int windowHeight;
};


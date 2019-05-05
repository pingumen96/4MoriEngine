#pragma once
#include <GLFW/glfw3.h>

namespace QuattroMori {
	class Renderer {
	public:
		Renderer(int width, int height);

		void render();
	private:
		void init();

		int width;
		int height;

		GLFWwindow* window;
	};
}


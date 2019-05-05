#include "Renderer.h"

Renderer::Renderer(int width, int height) :
	width(width),
	height(height),
	window(nullptr) {
	init();
}

void Renderer::init() {
	if(!glfwInit()) {
		return;
	}

	window = glfwCreateWindow(width, height, "Prova", NULL, NULL);
	if(!window) {
		glfwTerminate();
		return;
	}

	glfwMakeContextCurrent(window);
}

void Renderer::render() {
	glClear(GL_COLOR_BUFFER_BIT);
	glfwSwapBuffers(window);
	glfwPollEvents();
}
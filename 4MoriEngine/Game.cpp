#include "SceneGraph.h"
#include "Renderer.h"
#include "GameObject.h"
#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtx/string_cast.hpp>
#include <glm/gtc/quaternion.hpp>
#include "Game.h"

using namespace QuattroMori;

Game::Game() :
	renderer(nullptr),
	sceneGraph(nullptr),
	gameObjects(std::vector<GameObject*>()){
	renderer = new Renderer(500, 500);
	load();
}

void Game::runLoop() {
	while(!glfwWindowShouldClose(renderer->getWindow())) {
		renderer->render();
	}

	for(auto go : gameObjects) {
		std::cout << go->getId() << " " << glm::to_string(go->getWorldTransform()) << std::endl;
	}

	std::system("pause");
}

const unsigned int Game::getId() {
	return idCounter++;
}

void Game::load() {
	// il primo oggetto che si carica è la radice di tutti gli altri
	gameObjects.emplace_back(SceneGraph::getRoot());

	gameObjects.emplace_back(new GameObject(glm::vec3(1.0f, 1.0f, 1.0f), glm::fquat()));
	gameObjects.emplace_back(new GameObject(glm::vec3(2.0f, 2.0f, 1.0f), glm::fquat()));
	gameObjects.emplace_back(new GameObject(gameObjects[1], glm::vec3(1.0f, 2.0f, 1.0f), glm::fquat()));
}

unsigned int Game::idCounter = 0;

#include "SceneGraph.h"
#include "Renderer.h"
#include "GameObject.h"
#include "Game.h"

using namespace QuattroMori;

Game::Game() :
	renderer(nullptr),
	sceneGraph(nullptr),
	gameObjects(std::vector<std::shared_ptr<GameObject>>()){
	renderer = new Renderer(500, 500);
}

void Game::runLoop() {
	while(true) {
		renderer->render();
	}
}

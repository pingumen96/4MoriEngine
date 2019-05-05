#include "SceneGraph.h"
#include "Renderer.h"
#include "Game.h"

Game::Game() :
	renderer(nullptr),
	sceneGraph(nullptr) {
	renderer = new Renderer(500, 500);
}

void Game::runLoop() {
	while(true) {
		renderer->render();
	}
}

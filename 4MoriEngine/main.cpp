#include "Game.h"

Game* game;

int main() {
	game = new Game();

	game->runLoop();
}
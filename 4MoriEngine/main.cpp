#include "Game.h"

QuattroMori::Game* game;

int main() {
	game = new QuattroMori::Game();

	game->runLoop();
}
#pragma once

class Game {
public:
	Game();
	void runLoop();
private:
	class SceneGraph* sceneGraph;
	class Renderer* renderer;
};
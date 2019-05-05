#pragma once
#include <vector>
#include <memory>

namespace QuattroMori {
	class Game {
	public:
		Game();
		void runLoop();

		static const unsigned int getId();
	private:
		class SceneGraph* sceneGraph;
		class Renderer* renderer;
		std::vector<std::shared_ptr<class GameObject>> gameObjects;

		void load();

		static unsigned int idCounter;
	};
}


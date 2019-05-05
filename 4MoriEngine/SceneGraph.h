#pragma once
#include <vector>

namespace QuattroMori {
	class SceneGraph {
	private:
		std::vector<class GameObject> gameObjects;
		static const class GameObject root;
	};
}
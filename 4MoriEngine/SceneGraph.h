#pragma once
#include <memory>
#include <vector>

namespace QuattroMori {
	class SceneGraph {
	public:
		SceneGraph();
		static class GameObject* getRoot();
	private:
		static class GameObject* root;
	};
}
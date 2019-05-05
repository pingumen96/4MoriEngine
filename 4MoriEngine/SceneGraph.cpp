#include <memory>
#include "SceneGraph.h"
#include "GameObject.h"

using namespace QuattroMori;

GameObject* SceneGraph::root = nullptr;

SceneGraph::SceneGraph() {
}

GameObject* SceneGraph::getRoot() {
	if(root == nullptr) {
		root = new GameObject(nullptr, glm::vec3(0.0f, 0.0f, 0.0f), glm::fquat());
	}
	return root;
}

#include <memory>
#include "SceneGraph.h"
#include "GameObject.h"

using namespace QuattroMori;

std::shared_ptr<GameObject> SceneGraph::root = nullptr;

SceneGraph::SceneGraph() {
}

const std::shared_ptr<class GameObject> QuattroMori::SceneGraph::getRoot() {
	if(root == nullptr) {
		root = std::make_shared<GameObject>(nullptr, glm::vec3(0.0f, 0.0f, 0.0f), glm::fquat());
	}
	return root;
}

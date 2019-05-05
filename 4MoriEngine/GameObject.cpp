#include "GameObject.h"
#include "SceneGraph.h"
#include "AComponent.h"
#include "Game.h"

using namespace QuattroMori;


GameObject::GameObject(std::shared_ptr<GameObject> parent, glm::vec3 position, glm::fquat rotation) :
	parent(parent),
	transform(glm::translate(glm::mat4(1.0f), position)),
	rotation(rotation),
	components(std::vector<std::unique_ptr<AComponent>>()) {
	id = Game::getId();
}

GameObject::GameObject(glm::vec3 position, glm::fquat rotation):
	GameObject(SceneGraph::getRoot(), position, rotation){
}


GameObject::~GameObject() {
}

glm::mat4 GameObject::getWorldTransform() {
	if(parent == nullptr) {
		return transform;
	} else {
		return parent->getWorldTransform() * transform;
	}
}

#include "GameObject.h"
#include "SceneGraph.h"
#include "AComponent.h"
#include "Game.h"

using namespace QuattroMori;


GameObject::GameObject(GameObject* parent, glm::vec3 position, glm::fquat rotation) :
	parent(parent),
	state(State::Active),
	transform(glm::translate(glm::mat4(1.0f), position)),
	rotation(rotation),
	components(std::vector<std::unique_ptr<AComponent>>()) {
	if(parent != nullptr) {
		parent->addChild(this);
	}
	id = Game::getId();
}

GameObject::GameObject(glm::vec3 position, glm::fquat rotation):
	GameObject(SceneGraph::getRoot(), position, rotation){
}


GameObject::~GameObject() {
	for(auto child : children) {
		delete child;
	}
	children.clear();
	children.shrink_to_fit();
}

glm::mat4 GameObject::getWorldTransform() {
	if(parent == nullptr) {
		return transform;
	} else {
		return parent->getWorldTransform() * transform;
	}
}

void GameObject::update() {
	for(int i = 0; i < components.size(); i++) {
		components[i]->update();
	}
}

void QuattroMori::GameObject::addChild(GameObject* child) {
	children.emplace_back(child);
}

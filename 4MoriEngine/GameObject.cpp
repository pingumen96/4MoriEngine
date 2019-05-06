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

GameObject::GameObject(const GameObject& src) :
	GameObject(src.parent, glm::vec3(src.transform[3][0], src.transform[3][1], src.transform[3][2]), src.rotation) {
	for(size_t i = 0; i < src.children.size(); i++) {
		this->addChild(new GameObject(*(src.children[i])));
	}

	for(size_t i = 0; i < src.components.size(); i++) {
		// TODO: creare metodo addComponent, simile ad addChild
	}
}

GameObject::GameObject(glm::vec3 position, glm::fquat rotation) :
	GameObject(SceneGraph::getRoot(), position, rotation) {
}


GameObject::~GameObject() {
	for(auto child : children) {
		delete child;
		child = nullptr;
	}
	children.clear();
	children.shrink_to_fit();
}

glm::mat4 GameObject::getWorldTransform() {
	if(parent == nullptr) {
		return transform;
	} else {
		return parent->getWorldTransform()* transform;
	}
}

void GameObject::update() {
	for(size_t i = 0; i < components.size(); i++) {
		components[i]->update();
	}
}

GameObject& GameObject::operator=(const GameObject& r) {
	if(this == &r) {
		return *this;
	}

	this->transform = r.transform;
	this->rotation = r.rotation;
	this->parent = r.parent;

	for(size_t i = 0; i < r.children.size(); i++) {
		this->addChild(new GameObject(*(r.children[i])));
		//this->children.emplace_back(new GameObject(*(r.children[i])));
	}
	//this->
}

void QuattroMori::GameObject::addChild(GameObject* child) {
	children.emplace_back(child);
}

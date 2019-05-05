#include "GameObject.h"
#include "SceneGraph.h"
#include "AComponent.h"

using namespace QuattroMori;


GameObject::GameObject(std::shared_ptr<GameObject> parent, glm::mat4 transform, glm::fquat rotation) :
	parent(parent),
	transform(transform),
	rotation(rotation),
	components(std::vector<std::unique_ptr<AComponent>>()) {
}

GameObject::GameObject(glm::mat4 transform, glm::fquat rotation):
	GameObject(SceneGraph::root, transform, rotation){
}


GameObject::~GameObject() {
}

glm::mat4 GameObject::getWorldTransform() {
	return parent->getWorldTransform() * transform;
}

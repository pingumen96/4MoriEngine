#include "GameObject.h"
#include "AComponent.h"

using namespace QuattroMori;

GameObject::GameObject(glm::mat4 transform, glm::fquat rotation):
	transform(transform),
	rotation(rotation),
	components(std::vector<std::shared_ptr<AComponent>>()){
}


GameObject::~GameObject() {
}

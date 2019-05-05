#include "AComponent.h"
#include "GameObject.h"

using namespace QuattroMori;

AComponent::AComponent(std::shared_ptr<GameObject> owner) :
	owner(owner){
}

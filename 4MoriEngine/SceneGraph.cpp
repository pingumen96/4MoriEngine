#include "SceneGraph.h"
#include "GameObject.h"

using namespace QuattroMori;

const std::shared_ptr<class GameObject> SceneGraph::root = std::make_shared<GameObject>(glm::mat4(), glm::fquat());

QuattroMori::SceneGraph::SceneGraph() {
}

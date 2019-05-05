#include "SceneGraph.h"
#include "GameObject.h"

using namespace QuattroMori;

const GameObject SceneGraph::root = GameObject(glm::mat4(), glm::fquat());
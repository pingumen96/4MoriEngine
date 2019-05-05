#pragma once
#include <memory>
#include <vector>
#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>

namespace QuattroMori {
	class GameObject {
	public:
		GameObject(glm::mat4 transform, glm::fquat rotation);
		~GameObject();

		const glm::mat4& getTransform() { return transform; }
		const glm::fquat getRotation() { return rotation; }
	private:
		glm::mat4 transform;
		glm::fquat rotation;

		// object components
		std::vector<std::shared_ptr<class AComponent>> components;

		// scene graph management
		std::shared_ptr<GameObject> parent;
		std::vector<std::shared_ptr<GameObject>> children;
	};
}
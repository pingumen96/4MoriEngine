#pragma once
#include <memory>
#include <vector>
#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>

namespace QuattroMori {
	class GameObject {
	public:
		GameObject(glm::mat4 transform, glm::fquat rotation);
		GameObject(std::shared_ptr<GameObject> parent, glm::mat4 transform, glm::fquat rotation);
		~GameObject();

		const glm::mat4& getTransform() { return transform; }
		const glm::fquat& getRotation() { return rotation; }
		glm::mat4 getWorldTransform();
	private:
		glm::mat4 transform;
		glm::fquat rotation;

		// object components
		std::vector<std::unique_ptr<class AComponent>> components;

		// scene graph management
		std::shared_ptr<GameObject> parent;
		std::vector<std::shared_ptr<GameObject>> children;
	};
}
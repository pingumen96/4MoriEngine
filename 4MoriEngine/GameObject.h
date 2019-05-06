#pragma once
#include <memory>
#include <vector>
#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>

namespace QuattroMori {
	class GameObject {
	public:
		enum class State {Active, Inactive, Dead};
		GameObject() = delete;
		GameObject(const GameObject& src);
		GameObject(glm::vec3 position, glm::fquat rotation);
		GameObject(GameObject* parent, glm::vec3 position, glm::fquat rotation);
		~GameObject();

		const glm::mat4& getTransform() const { return transform; }
		const glm::fquat& getRotation() const { return rotation; }
		glm::mat4 getWorldTransform();

		unsigned int getId() const { return id; }

		void update();

		GameObject& operator=(const GameObject& r);
	private:
		glm::mat4 transform;
		glm::fquat rotation;
		State state;

		// object components
		std::vector<std::unique_ptr<class AComponent>> components;

		// scene graph management
		GameObject* parent;
		std::vector<GameObject*> children;
		void addChild(GameObject* child);

		unsigned int id;
	};
}
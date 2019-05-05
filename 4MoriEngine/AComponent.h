#pragma once
#include <memory>


namespace QuattroMori {
	class AComponent {
	public:
		AComponent(std::shared_ptr<class GameObject> owner);
		virtual void update() = 0;
	private:
		std::shared_ptr<class GameObject> owner;
	};
}


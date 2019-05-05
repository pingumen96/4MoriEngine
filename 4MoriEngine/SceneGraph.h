#pragma once
#include <memory>
#include <vector>

namespace QuattroMori {
	class SceneGraph {
	public:
		SceneGraph();
		static const std::shared_ptr<class GameObject> getRoot();
	private:
		static std::shared_ptr<class GameObject> root;
	};
}
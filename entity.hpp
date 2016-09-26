#ifndef __ENTITY_HPP__
#define __ENTITY_HPP__

#include "component.hpp"
#include <memory>
#include <unordered_map>

class Entity final {
	private:
		unsigned long id_;
		std::unordered_map<ComponentId, std::shared_ptr<Component>> components_;
	public:
		Entity(const unsigned long id): id_{id} {}
		Entity(const Entity&) = delete;
		Entity& operator=(const Entity&) = delete;

		template <typename T>
		std::shared_ptr<T> getComponent() {
			ComponentId id = getComponentId<T>();
			if(components_.count(id) != 0) {
				return std::static_pointer_cast<T>(components_[id]);
			}
			else {
				return nullptr;
			}
		}

		void addComponent(std::shared_ptr<Component> c) {
			ComponentId id = getComponentId(c);
			components_.insert(std::pair<ComponentId, std::shared_ptr<Component>>(id, std::shared_ptr<Component>(c)));
		}
};


#endif

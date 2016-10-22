#ifndef __ENTITY_MANAGER_HPP__
#define __ENTITY_MANAGER_HPP__

#include <map>
#include <memory>
#include <vector>
#include "component.hpp"
#include "entity.hpp"

class EntityManager final {
	private:
		std::multimap<ComponentId, std::shared_ptr<Entity>> entitiesForComponent_;
		static EntityId nextId_;
	public:

		EntityManager() = default;
		EntityManager(const EntityManager&) = delete;
		EntityManager& operator=(const EntityManager&) = delete;

		template <typename T>
		void getEntitiesFor(std::vector<std::shared_ptr<Entity>>& result) {
			for(auto& e: entitiesForComponent_.equal_range(getComponentId<T>())) {
				result.push_back(e);
			}
		}

		void addComponentTo(Entity& e, std::shared_ptr<Component> c) {
			e.addComponent(c);
		}
};

#endif

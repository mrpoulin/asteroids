#ifndef __ENTITY_MANAGER_HPP__
#define __ENTITY_MANAGER_HPP__

#include <map>
#include <memory>
#include <vector>
#include "component.h"
#include "entity.h"

class EntityManager final {
	private:
		std::multimap<ComponentId, Entity::Ptr> entitiesForComponent_;
		static EntityId nextId_;
	public:

		EntityManager() = default;
		EntityManager(const EntityManager&) = delete;
		EntityManager& operator=(const EntityManager&) = delete;

		Entity::Ptr createEntity();

		template <typename T>
		void getEntitiesFor(std::vector<Entity::Ptr>& result) {
			auto range = entitiesForComponent_.equal_range(getComponentId<T>());
			for(auto e = range.first; e != range.second; ++e) {
				result.push_back(e->second);
			}
		}

		void addComponentTo(Entity::Ptr, std::shared_ptr<Component> c);


		typedef std::shared_ptr<EntityManager> Ptr;
};

#endif

/////////////////////////////////////////////////////////////////////////////////////////
// The entity manager stores every entity in the game and it's associated components.
// An entity is simply an integer that is akin to a primary key in a database. Each
// associated component represents a column. Fetching an entity gives us the row
// corresponding to that primary key, with the data for each associated component.
// Each system then reads/writes that data as necessary.
/////////////////////////////////////////////////////////////////////////////////////////

#ifndef ENTITY_ENTITY_MANAGER_H
#define ENTITY_ENTITY_MANAGER_H

#include <unordered_map>
#include <memory>
#include <list>
#include <vector>
#include "entity.h"
#include "components/component.h"

namespace asteroids {
namespace entity {

class EntityManager final {
public:

	// Disallow copying.
	EntityManager() = default;
	EntityManager(const EntityManager&) = delete;
	EntityManager& operator=(const EntityManager&) = delete;

	// Returns an unused entity (an entity is an integer)
	Entity createEntity();

	// Destroys an entity, allowing the entity to be 
	// reused later.
	void destroyEntity(const Entity& e);


	void addComponentTo(const Entity& e, const component::Component::Ptr c);
	
	// TODO: This
	// template <typename T>
	// void removeComponentFrom(const Entity& e);

	// ============= Query Functions =============

	// Query for every entity that is associated with the 
	// component of type T
	template <typename T>
	void getEntitiesFor(std::list<Entity>& results) {
		component::ComponentId componentId = component::getComponentId<T>();

		results.clear();

		auto iter = entitiesForComponent_.find(componentId);
		if(iter != entitiesForComponent_.end()) {
			for(const auto& pairs : iter->second) {
				results.push_back(pairs.first);
			}
		} 
	}

	// Get all components of the type T
	template <typename T>
	void getComponents(std::vector<component::Component::Ptr>& results) {
		component::ComponentId componentId = component::getComponentId<T>();

		results.clear();

		auto iter = entitiesForComponent_.find(componentId);
		if(iter != entitiesForComponent_.end()) {
			for(const auto& pairs : iter->second) {
				results.push_back(pairs.second);
			}
		} 
	}

	// Get the component of type T from the given entity.
	template <typename T>
	std::shared_ptr<T> getComponent(const Entity& entity) {
		component::ComponentId componentId = component::getComponentId<T>();

		auto componentMapIter = entitiesForComponent_.find(componentId);
		if(componentMapIter == entitiesForComponent_.end()) {
			return nullptr;
		}

		auto entityMapIter = componentMapIter->second.find(entity);
		if(entityMapIter == componentMapIter->second.end()) {
			return nullptr;
		}

		return std::static_pointer_cast<T>(entityMapIter->second);
	}

	typedef std::shared_ptr<EntityManager> Ptr;

private:
	std::unordered_map<component::ComponentId, std::unordered_map<Entity, component::Component::Ptr>> entitiesForComponent_;

	// List of every entity currently in use.
	std::list<Entity> entities_;

	// List of entities that have been released and can be reallocated.
	std::list<Entity> freeEnities_;

	// Next new free entity that can be allocated.
	static Entity nextEntity_;

	// Allocate a new entity
	Entity getNextEntity();

};

} // entity
} // asteroids

#endif // ENTITY_ENTITY_MANAGER_H

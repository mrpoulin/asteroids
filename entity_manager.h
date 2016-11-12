#ifndef __ENTITY_MANAGER_HPP__
#define __ENTITY_MANAGER_HPP__

#include <unordered_map>
#include <memory>
#include <list>
#include <vector>
#include "component.h"

typedef unsigned long long Entity;

class EntityManager final {
	private:
		std::unordered_map<ComponentId, std::unordered_map<Entity, Component::Ptr>> entitiesForComponent_;
		std::list<Entity> entities_;

		std::list<Entity> freeEnities_;
		static Entity nextEntity_;

		Entity getNextEntity();

	public:

		EntityManager() = default;
		EntityManager(const EntityManager&) = delete;
		EntityManager& operator=(const EntityManager&) = delete;

		Entity createEntity();
		void destroyEntity(const Entity& e);

		void addComponentTo(const Entity& e, const Component::Ptr c);

		// template <typename T>
		// void removeComponentFrom(const Entity& e);

		template <typename T>
		void getEntitiesFor(std::list<Entity>& results) {
			ComponentId componentId = getComponentId<T>();

			results.clear();

			auto iter = entitiesForComponent_.find(componentId);
			if(iter != entitiesForComponent_.end()) {
				for(auto& pairs : iter->second) {
					results.push_back(pairs.first);
				}
			} 
		}

		template <typename T>
		void getComponents(std::vector<Component::Ptr>& results) {
			ComponentId componentId = getComponentId<T>();

			results.clear();

			auto iter = entitiesForComponent_.find(componentId);
			if(iter != entitiesForComponent_.end()) {
				for(auto& pairs : iter->second) {
					results.push_back(pairs.second);
				}
			} 
		}

		template <typename T>
		std::shared_ptr<T> getComponent(const Entity& entity) {
			ComponentId componentId = getComponentId<T>();

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
};

#endif

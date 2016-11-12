#include "entity_manager.h"

Entity EntityManager::nextEntity_ = 0;

Entity EntityManager::getNextEntity() {
    if(!freeEnities_.empty()) {
        Entity next = freeEnities_.front();
        freeEnities_.pop_front();
        return next;
    } else {
        return nextEntity_++;
    }
}

Entity EntityManager::createEntity() {
    Entity e = getNextEntity();
    entities_.push_front(e);
    return e;
}

void EntityManager::destroyEntity(const Entity& e) {
    for(auto& entityMap : entitiesForComponent_) {
        entityMap.second.erase(e);
    }
    freeEnities_.push_back(e);
}


void EntityManager::addComponentTo(const Entity& e, Component::Ptr c) {
    ComponentId componentId = getComponentId(*c);

    auto iter = entitiesForComponent_.find(componentId);
    if(iter != entitiesForComponent_.end()) {
        iter->second[e] = c;
    } else {
        entitiesForComponent_[componentId] = {{e, c}};
    }
}
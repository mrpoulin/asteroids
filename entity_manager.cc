#include "entity_manager.h"

unsigned long EntityManager::nextId_ = 0;

Entity::Ptr EntityManager::createEntity() {
    return Entity::Ptr(new Entity(nextId_++));
}

void EntityManager::addComponentTo(Entity::Ptr e, std::shared_ptr<Component> c) {

    entitiesForComponent_.insert(std::make_pair(getComponentId(*c), e));
    e->addComponent(c);
}
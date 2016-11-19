#include <list>
#include "movement_system.h"
#include "screen_position_component.h"
#include "physics_component.h"

void MovementSystem::update(double delta) {
    std::list<Entity> screenPositionEntities;
    entityManager_->getEntitiesFor<ScreenPositionComponent>(screenPositionEntities);

    for(auto& entity: screenPositionEntities) {
        auto screenPos = entityManager_->getComponent<ScreenPositionComponent>(entity);
        auto physicsComponent = entityManager_->getComponent<PhysicsComponent>(entity);
        if(physicsComponent == nullptr) continue;

        screenPos->position += physicsComponent->velocity * (float)delta;

    }
}
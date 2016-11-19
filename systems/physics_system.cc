#include <list>
#include <cmath>
#include "physics_system.h"
#include "physics_component.h"
#include "screen_position_component.h"
#include <iostream>

void PhysicsSystem::update(double delta) {
    std::list<Entity> physicsEntities;
    entityManager_->getEntitiesFor<PhysicsComponent>(physicsEntities);

    for(auto &entity : physicsEntities) {
        auto physicsComponent = entityManager_->getComponent<PhysicsComponent>(entity);
        auto screenPos = entityManager_->getComponent<ScreenPositionComponent>(entity);

        float speed = euclideanNorm(physicsComponent->velocity);

        if(speed < physicsComponent->maxSpeed())
            physicsComponent->velocity += physicsComponent->rotationVector() * (float)delta * physicsComponent->acceleration;

        speed = euclideanNorm(physicsComponent->velocity);

        Vec2D<float> dv;
        float friction = physicsComponent->friction() * delta;
        if(speed > friction) {
            dv = friction * -(physicsComponent->velocity / speed);
        } else {
            dv = -physicsComponent->velocity;
        }

       physicsComponent->velocity += dv;
       screenPos->position += (physicsComponent->velocity - dv / 2.0f) * (float)delta;
    }
}

bool PhysicsSystem::handle(AccelerateState& s) {
    auto physicsComponent = entityManager_->getComponent<PhysicsComponent>(s.entity);
    if(physicsComponent == nullptr) return false;

    if(s.enabled) {
        physicsComponent->acceleration = s.acceleration;
    } else {
        physicsComponent->acceleration = 0;
    }

    return true;
}

 bool PhysicsSystem::handle(RotateState& s) {
     auto physicsComponent = entityManager_->getComponent<PhysicsComponent>(s.entity);
     if(physicsComponent == nullptr) return false;

     if(s.enabled) {
         physicsComponent->rotate(s.degrees);
     }

     return true;
 }
#include <list>
#include <cmath>
#include "physics_system.h"
#include "components/physics_component.h"
#include "components/screen_position_component.h"

namespace asteroids {
namespace system {

using component::PhysicsComponent;
using component::ScreenPositionComponent;
using common::ScreenPosition;
using common::LogicalQuantity;
using common::Vec2D;

void PhysicsSystem::update(double delta) {
    std::list<entity::Entity> physicsEntities;
    entityManager_->getEntitiesFor<PhysicsComponent>(physicsEntities);

    for(auto &entity : physicsEntities) {
        auto physicsComponent = entityManager_->getComponent<PhysicsComponent>(entity);
        auto screenPos = entityManager_->getComponent<ScreenPositionComponent>(entity);

        LogicalQuantity speed = euclideanNorm(physicsComponent->velocity);

        if(speed < physicsComponent->maxSpeed)
            physicsComponent->velocity += 
                static_cast<Vec2D<LogicalQuantity>>(physicsComponent->rotation)
                * static_cast<LogicalQuantity>(delta)
                * physicsComponent->acceleration;

        speed = euclideanNorm(physicsComponent->velocity);

        Vec2D<LogicalQuantity> dv;
        float friction = physicsComponent->friction * static_cast<LogicalQuantity>(delta);
        if(speed > friction) {
            dv = friction * -(physicsComponent->velocity / speed);
        } else {
            dv = -physicsComponent->velocity;
        }

       physicsComponent->velocity += dv;
       Vec2D<LogicalQuantity> tmp = (physicsComponent->velocity - dv / 2.0f) * static_cast<LogicalQuantity>(delta);
       screenPos->position.x += (ScreenPosition)tmp.x;
       screenPos->position.y += (ScreenPosition)tmp.y;
    }
}

bool PhysicsSystem::handle(message::AccelerateState& s) {
    auto physicsComponent = entityManager_->getComponent<PhysicsComponent>(s.entity);
    if(physicsComponent == nullptr) return false;

    if(s.enabled) {
        physicsComponent->acceleration = s.acceleration;
    } else {
        physicsComponent->acceleration = 0;
    }

    return true;
}

 bool PhysicsSystem::handle(message::RotateState& s) {
     auto physicsComponent = entityManager_->getComponent<PhysicsComponent>(s.entity);
     if(physicsComponent == nullptr) return false;

     if(s.enabled) {
         physicsComponent->rotation += common::degreeToRad(s.rotation);
     }

     return true;
 }

} // system
} // asteroids

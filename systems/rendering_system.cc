#include "rendering_system.h"
#include "components/sprite_component.h"
#include "components/screen_position_component.h"
#include "components/physics_component.h"
#include <list>
#include <iostream>


namespace asteroids {
namespace system {

using entity::EntityManager;
using entity::Entity;
using component::SpriteComponent;
using component::PhysicsComponent;
using component::ScreenPositionComponent;
using graphics::Renderable;
using common::Vec2D;

RenderingSystem::RenderingSystem(EntityManager::Ptr em, SDL_Renderer* renderer): entityManager_{em}, renderer_{renderer} {
}

void RenderingSystem::update(double delta) {

    std::list<Entity> spriteEntities;
    entityManager_->getEntitiesFor<SpriteComponent>(spriteEntities);

    for(auto& entity : spriteEntities) {
        auto screenPosComp = entityManager_->getComponent<ScreenPositionComponent>(entity);

        auto spriteComp = entityManager_->getComponent<SpriteComponent>(entity);
        auto physicsComp = entityManager_->getComponent<PhysicsComponent>(entity);

        Renderable::Ptr renderable = spriteComp->renderable;

        SpriteComponent::Frame frame;

        if(!spriteComp->getCurrentFrame(frame)) {
            std::cerr << "Error getting current frame for sprite." << std::endl;
            return;
        }

        Vec2D<common::ScreenPosition> center(frame.width / 2, frame.height / 2);

        InterpolatingState currentState;
        currentState.physics = *physicsComp;
        currentState.position = *screenPosComp;

        InterpolatingState state;
        // Do interpolation
        if (oldState_) {
            state.position.position = static_cast<Vec2D<int>>(
            (Vec2D<float>)currentState.position.position * (float)delta + 
            (Vec2D<float>)oldState_->position.position * (1-(float)delta));
        } 
        oldState_ = currentState;

        renderable->render(renderer_, 
                           {frame.x, frame.y, frame.width, frame.height},
                           {state.position.position.x, state.position.position.y, frame.width, frame.height},
                           physicsComp->rotation.asDegrees(),
                           center
                          );
    }
}

} // system
} // asteroids

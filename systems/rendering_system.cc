#include "rendering_system.h"
#include "components/sprite_component.h"
#include "components/screen_position_component.h"
#include "components/physics_component.h"
#include <list>
#include <iostream>


RenderingSystem::RenderingSystem(EntityManager::Ptr em, SDL_Renderer* renderer): entityManager_{em}, renderer_{renderer} {
}

void RenderingSystem::update(double delta) {

    std::list<Entity> spriteEntities;
    entityManager_->getEntitiesFor<AnimatedSpriteComponent>(spriteEntities);

    for(auto& entity : spriteEntities) {
        auto screenPosComp = entityManager_->getComponent<ScreenPositionComponent>(entity);

        auto spriteComp = entityManager_->getComponent<AnimatedSpriteComponent>(entity);
        auto physicsComp = entityManager_->getComponent<PhysicsComponent>(entity);

        RenderableInterface::Ptr renderable = spriteComp->renderable();

        SpriteFrame frame;

        if(!spriteComp->getCurrentFrame(frame)) {
            std::cerr << "Error getting current frame for sprite." << std::endl;
            return;
        }

        Vec2D<float> center;
        center.x = frame.width / 2;
        center.y = frame.height / 2;

        InterpolatingState currentState;
        currentState.physics = *physicsComp;
        currentState.position = *screenPosComp;

        InterpolatingState state;
        // Do interpolation
        if (oldState_) {
            state.position.position = currentState.position.position * (float)delta + oldState_->position.position * (1-(float)delta);
        } 
        oldState_ = currentState;

        renderable->render(renderer_, 
                           {frame.x, frame.y, frame.width, frame.height},
                           {(int)state.position.position.x, (int)state.position.position.y, frame.width, frame.height},
                           physicsComp->rotation(),
                           center
                          );
    }
}
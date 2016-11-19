#include "rendering_system.h"
#include "sprite_component.h"
#include "screen_position_component.h"
#include "physics_component.h"
#include <list>
#include <iostream>

RenderingSystem::RenderingSystem(EntityManager::Ptr em, SDL_Renderer* renderer): entityManager_{em}, renderer_{renderer} {
}

void RenderingSystem::update(double delta) {

    std::list<Entity> spriteEntities;
    entityManager_->getEntitiesFor<SpriteComponent>(spriteEntities);

    for(auto& entity : spriteEntities) {
        auto screenPosComp = entityManager_->getComponent<ScreenPositionComponent>(entity);
        auto spriteComp = entityManager_->getComponent<SpriteComponent>(entity);
        auto physicsComp = entityManager_->getComponent<PhysicsComponent>(entity);

        RenderableInterface::Ptr renderable = spriteComp->renderable();

        Vec2D<float> center;
        center.x = spriteComp->width() / 2;
        center.y = spriteComp->height() / 2;

        renderable->render(renderer_, 
                           {spriteComp->x(), spriteComp->y(), spriteComp->width(), spriteComp->height()},
                           {(int)screenPosComp->position.x, (int)screenPosComp->position.y, spriteComp->width(), spriteComp->height()},
                           physicsComp->rotation(),
                           center
                          );
    }
}
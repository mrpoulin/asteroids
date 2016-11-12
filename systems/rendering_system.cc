#include "rendering_system.h"
#include "sprite_component.h"
#include "screen_position_component.h"
#include <list>

RenderingSystem::RenderingSystem(EntityManager::Ptr em, SDL_Renderer* renderer): entityManager_{em}, renderer_{renderer} {

}

void RenderingSystem::update(double delta) {

    std::list<Entity> spriteEntities;
    entityManager_->getEntitiesFor<SpriteComponent>(spriteEntities);

    for(auto& entity : spriteEntities) {
        std::shared_ptr<ScreenPositionComponent> screenPosComp = entityManager_->getComponent<ScreenPositionComponent>(entity);
        std::shared_ptr<SpriteComponent> spriteComp = entityManager_->getComponent<SpriteComponent>(entity);

        RenderableInterface::Ptr renderable = spriteComp->renderable();
        renderable->render(renderer_, 
                           {spriteComp->x(), spriteComp->y(), spriteComp->width(), spriteComp->height()},
                           {screenPosComp->position().x, screenPosComp->position().y, spriteComp->width(), spriteComp->height()}
                          );
    }
}
#ifndef SYSTEM_RENDERING_SYSTEM_H_
#define SYSTEM_RENDERING_SYSTEM_H_

#include <memory>
#include "system.h"
#include "entity_manager.h"
#include <SDL.h>

class RenderingSystem : public System{
  public:
    RenderingSystem(EntityManager::Ptr em, SDL_Renderer*);

    virtual void update(double delta) override;
  private:
    EntityManager::Ptr entityManager_;
    SDL_Renderer* renderer_;
};

#endif
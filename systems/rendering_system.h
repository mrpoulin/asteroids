#ifndef SYSTEM_RENDERING_SYSTEM_H_
#define SYSTEM_RENDERING_SYSTEM_H_

#include <memory>
#include <experimental/optional>
#include <SDL.h>

#include "system.h"
#include "entity/entity_manager.h"
#include "components/screen_position_component.h"
#include "components/physics_component.h"

class RenderingSystem : public System {
  public:
    RenderingSystem(EntityManager::Ptr em, SDL_Renderer*);

    virtual void update(double delta) override;
  private:

    struct InterpolatingState {
      PhysicsComponent physics;
      ScreenPositionComponent position;
    };

    EntityManager::Ptr entityManager_;
    SDL_Renderer* renderer_;

    std::experimental::optional<InterpolatingState> oldState_;
};

#endif
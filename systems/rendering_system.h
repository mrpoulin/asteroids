#ifndef SYSTEM_RENDERING_SYSTEM_H
#define SYSTEM_RENDERING_SYSTEM_H

#include <memory>
#include <experimental/optional>
#include <SDL.h>

#include "system.h"
#include "entity/entity_manager.h"
#include "components/screen_position_component.h"
#include "components/physics_component.h"

namespace asteroids {
namespace system {

class RenderingSystem : public System {
  public:
    RenderingSystem(entity::EntityManager::Ptr em, SDL_Renderer*);

    virtual void update(double delta) override;
  private:

    struct InterpolatingState {
      component::PhysicsComponent physics;
      component::ScreenPositionComponent position;
    };

    entity::EntityManager::Ptr entityManager_;
    SDL_Renderer* renderer_;

    std::experimental::optional<InterpolatingState> oldState_;
};

} // system
} // asteroids

#endif // SYSTEM_RENDERING_SYSTEM_H

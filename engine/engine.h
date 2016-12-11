/////////////////////////////////////////////////////////////////////////////////////////
// The heart of the game. Takes care of all SDL stuff, and manages systems.
/////////////////////////////////////////////////////////////////////////////////////////

#ifndef ENGINE_ENGINE_H
#define ENGINE_ENGINE_H

#include <SDL.h>
#include <memory>
#include <string>
#include <list>
#include "entity/entity_manager.h"
#include "systems/input_system.h"
#include "systems/rendering_system.h"
#include "graphics/texture_manager.h"
#include "components/component.h"
#include "systems/system.h"
#include "input/context.h"

namespace asteroids {
namespace engine {

// Facade for various components.
class Engine final {
public:

    Engine(entity::EntityManager::Ptr em);

    // ============= Entity/Component Stuff =============
    // The entity manager is needed by every system, therefore it needs to be exposed.
    entity::EntityManager::Ptr entityManager() { return entityManager_ ;}

    Entity createEntity(const std::list<const component::Component::Ptr> components);

    // Systems are stored in a list. The first system added
    // is therefore the first system run.
    void addSystem(const system::System::Ptr system);

    // ============= Input Stuff =============
    // Systems registered as an input listener will receive input events.
    void addInputListener(const system::System::Ptr system);
    void addContext(const input::Context::Ptr context);

    // ============= Rendering Stuff =============
    graphics::Texture::Ptr getTexture(std::string path) {
        return textureManager_.loadTexture(sdlRenderer_, path);
    }

    // ============= Game loop stuff =============
    void run();

private:
    // ============= SDL Stuff =============
    SDL_Window* sdlMainWindow_;
	SDL_Renderer* sdlRenderer_;

    void initSDL();
    void teardownSDL();

    // ============= Entity/Component Stuff =============
    entity::EntityManager::Ptr entityManager_;
    // User supplied systems
    std::list<system::System::Ptr> systems_;

   // ============= Input Stuff =============
    input::Keyboard::Ptr keyboard_;
    // The input system is required and therefore not supplied by the user.
    // It always runs first, outside of the game loop.
    // TODO unique_ptr
    std::shared_ptr<system::InputSystem> inputSystem_;

    // ============= Rendering Stuff =============
    graphics::TextureManager textureManager_;

    // Like the input system, the rendering system is required.
    // It always runs last.
    // TODO unique_ptr
    std::shared_ptr<system::RenderingSystem> renderingSystem_;

    // ============= Game loop stuff =============
    static constexpr double UPDATES_PER_SECOND = 25;
	static constexpr double DELAY_TICKS = 1000 / UPDATES_PER_SECOND;
	static constexpr double MAX_UPDATES = 5;


};

} // engine
} // asteroids

#endif // ENGINE_ENGINE_H
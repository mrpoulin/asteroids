#ifndef __ENGINE_H__
#define __ENGINE_H__

#include <SDL.h>
#include <memory>
#include <string>
#include <list>
#include "entity_manager.h"
#include "input_system.h"
#include "rendering_system.h"
#include "action.h"
#include "context.h"
#include "texture_manager.h"
#include "component.h"
#include "system.h"

// Facade for various components.
class Engine final {
private:

    // SDL Stuff
    SDL_Window* sdlMainWindow_;
	SDL_Renderer* sdlRenderer_;

    // Entity/Component stuff
    EntityManager::Ptr entityManager_;
    std::list<System::Ptr> systems_;

    // Input stuff
    Keyboard::Ptr keyboard_;
    std::shared_ptr<InputSystem> inputSystem_;

    // Rendering stuff
    TextureManager textureManager_;
    std::shared_ptr<RenderingSystem> renderingSystem_;

    // Game loop stuff
    static constexpr double UPDATES_PER_SECOND = 25;
	static constexpr double DELAY_TICKS = 1000 / UPDATES_PER_SECOND;
	static constexpr double MAX_UPDATES = 5;

    void initSDL();
    void teardownSDL();

public:

    Engine(EntityManager::Ptr em);

    // Entity/Component Stuff

    // Required by systems, for now.
    EntityManager::Ptr entityManager() { return entityManager_ ;}
    Entity createEntity(const std::list<const Component::Ptr> components);
    void addSystem(const System::Ptr system);

    // Input Stuff
    void addInputListener(const System::Ptr system);
    void addContext(const Context::Ptr context);

    // Rendering Stuff
    Texture::Ptr getTexture(std::string path) {
        return textureManager_.loadTexture(sdlRenderer_, path);
    }

    // Game loop stuff
    void run();

};

#endif
#include "engine.h"
#include "input/sdl_keyboard.h"
#include <iostream>

namespace asteroids {
namespace engine {

using namespace input;
using namespace system;
using namespace entity;

void Engine::initSDL() {

    if(SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR,
            "Error initializing SDL",
            SDL_GetError(),
            nullptr);
        SDL_Quit();
    }

    auto status = SDL_CreateWindowAndRenderer(0, 0,
		SDL_WINDOW_FULLSCREEN_DESKTOP,
        &sdlMainWindow_, &sdlRenderer_);

    if(status != 0) {
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR,
			"Error creating window.",
			SDL_GetError(),
			nullptr);
        SDL_Quit();
	}

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");  // make the scaled rendering look smoother.
	SDL_RenderSetLogicalSize(sdlRenderer_, 1024, 768);
}

void Engine::teardownSDL() {
    if(sdlMainWindow_)
        SDL_DestroyWindow(sdlMainWindow_);

    if(sdlRenderer_)
	    SDL_DestroyRenderer(sdlRenderer_);

	SDL_Quit();
}

Engine::Engine(EntityManager::Ptr em): entityManager_(em),
									   keyboard_(new SDLKeyboard()),
									   inputSystem_(std::shared_ptr<InputSystem>(new InputSystem(keyboard_)))

{
    initSDL();
	renderingSystem_ = std::shared_ptr<RenderingSystem>(new RenderingSystem(entityManager_, sdlRenderer_));
}

Entity Engine::createEntity(const std::list<const component::Component::Ptr> components) {
	entity::Entity e = entityManager_->createEntity();
	for(auto &component : components) {
		entityManager_->addComponentTo(e, component);
	}

	return e;
}

void Engine::addSystem(const System::Ptr system) {
	systems_.push_back(system);
}

void Engine::addInputListener(const System::Ptr system) {
	inputSystem_->registerListener(system);
}

void Engine::addContext(const Context::Ptr context) {
	inputSystem_->pushContext(context);
}

void Engine::run() {
    bool running = true;
	SDL_Event e;

	const float dt = 1;
	float accumulator = 0;

	float currentTime = SDL_GetTicks();

	while(running) {

		while(SDL_PollEvent(&e) != 0) {
			switch(e.type) {
				case SDL_QUIT:
					running = false;
					break;
			}
		}
		inputSystem_->update(0);

		const auto newTime = SDL_GetTicks();
		float frameTime = newTime - currentTime;

		if (frameTime > 0.25)
			frameTime = 0.25;
		
		currentTime = newTime;
		accumulator += frameTime;


		while(accumulator >= dt) {
			for(auto &system : systems_) {
				system->update(dt);
			}

			accumulator -= dt;
		}

		const double alpha = accumulator / dt;

		// Rendering set up screen
		SDL_RenderClear(sdlRenderer_);
		// Alpha is the interpolation value.
		renderingSystem_->update(alpha);
		SDL_RenderPresent(sdlRenderer_);
	}
}

} // engine
} // asteroids

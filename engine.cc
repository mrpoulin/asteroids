#include "engine.h"
#include <iostream>

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

Engine::Engine(): entityManager_(EntityManager::Ptr(new EntityManager())),
				  keyboard_(Keyboard::Ptr(new SDLKeyboard())),
				  inputSystem_(std::shared_ptr<InputSystem>(new InputSystem(keyboard_)))

{
    initSDL();
	renderingSystem_ = std::shared_ptr<RenderingSystem>(new RenderingSystem(entityManager_, sdlRenderer_));
}

Entity Engine::createEntity(const std::list<const Component::Ptr> components) {
	Entity e = entityManager_->createEntity();
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
	inputSystem_->registerContext(context);
}

void Engine::run() {
    bool running = true;
	SDL_Event e;

    double nextUpdateTick = SDL_GetTicks();

	while(running) {

		for(auto updates = 0; SDL_GetTicks() > nextUpdateTick && updates < MAX_UPDATES; ++updates) {

			while(SDL_PollEvent(&e) != 0) {
				switch(e.type) {
					case SDL_QUIT:
						running = false;
						break;
				}
			}

			inputSystem_->update(0);
			for(auto &system : systems_) {
				system->update(0);
			}
			nextUpdateTick += DELAY_TICKS;
		}

		double delta = 1 - (nextUpdateTick - SDL_GetTicks() / (double) DELAY_TICKS);

		// Rendering set up screen
		//SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderClear(sdlRenderer_);
		renderingSystem_->update(delta);
		SDL_RenderPresent(sdlRenderer_);
	}
}
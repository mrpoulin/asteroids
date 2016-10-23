#include <iostream>
#include <SDL.h>
#include <memory>
#include "input_system.hpp"
#include "action.hpp"
#include "test_system.hpp"

int main() {

	if(SDL_Init(SDL_INIT_EVERYTHING) != 0) {

		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR,
			"Error initializing SDL",
			SDL_GetError(),
			nullptr);
	}

	SDL_Window* mainWindow;
	SDL_Renderer* renderer;

	auto status = SDL_CreateWindowAndRenderer(0, 0,
		SDL_WINDOW_FULLSCREEN_DESKTOP,
        &mainWindow, &renderer);

	if(status != 0) {
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR,
			"Error creating window.",
			SDL_GetError(),
			nullptr);
	}

	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");  // make the scaled rendering look smoother.
	SDL_RenderSetLogicalSize(renderer, 1024, 768);

	// Setup game stuff.
	auto entityManager = std::shared_ptr<EntityManager>(new EntityManager());
	auto keyboard = std::shared_ptr<Keyboard>(new SDLKeyboard());

	auto inputSystem = std::shared_ptr<InputSystem>(new InputSystem(entityManager, keyboard));
	auto testSystem = std::shared_ptr<TestSystem>(new TestSystem(entityManager));

	auto basicContext = std::shared_ptr<Context>(new Context());
	basicContext->addAction(Keyboard::Key::A, new NullAction());

	inputSystem->registerListener(testSystem);
	inputSystem->registerContext(basicContext);

	bool running = true;
	SDL_Event e;

	constexpr double UPDATES_PER_SECOND = 25;
	constexpr double DELAY_TICKS = 1000 / UPDATES_PER_SECOND;
	constexpr double MAX_UPDATES = 5;

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

			inputSystem->update(0);
			// Other updating stuff.

			nextUpdateTick += DELAY_TICKS;
		}

		double delta = 1 - (nextUpdateTick - SDL_GetTicks() / (double) DELAY_TICKS);

		// Rendering set up screen
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderClear(renderer);
		SDL_RenderPresent(renderer);
		// renderingSystem->render()
	}

	SDL_DestroyWindow(mainWindow);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();

	return 0;
}

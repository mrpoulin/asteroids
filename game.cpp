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

	bool running = true;
	SDL_Event e;

	// Setup game stuff.
	auto entityManager = std::shared_ptr<EntityManager>(new EntityManager());
	auto keyboard = std::shared_ptr<Keyboard>(new SDLKeyboard());

	auto inputSystem = std::shared_ptr<InputSystem>(new InputSystem(entityManager, keyboard));
	auto testSystem = std::shared_ptr<TestSystem>(new TestSystem(entityManager));

	auto basicContext = std::shared_ptr<Context>(new Context());
	basicContext->addAction(Keyboard::Key::A, new NullAction());

	inputSystem->registerListener(testSystem);
	inputSystem->registerContext(basicContext);

	// TODO: Yes, fix this.
	while(running) {
		while(SDL_PollEvent(&e) != 0) {
			switch(e.type) {
				case SDL_QUIT:
					running = false;
					break;
			}
		}

		inputSystem->update();
	}

	SDL_DestroyWindow(mainWindow);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();

	return 0;
}

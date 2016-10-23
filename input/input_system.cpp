#include "input_system.hpp"
#include <iostream>

InputSystem::InputSystem(std::shared_ptr<EntityManager> em, std::shared_ptr<Keyboard> kb): 
	System{em}, keyboard_{kb} {
}

void InputSystem::registerContext(std::shared_ptr<Context> c) {
	contexts_.push_front(c);
}

void InputSystem::registerListener(std::shared_ptr<System> l) {
	listeners_.push_front(l);
}

void InputSystem::update(double delta) {

	keyboard_->update();

	// Map all keyboard input.
	std::list<Action*> actions;
	keyboard_->each([&](Keyboard::Key k) {
		if(keyboard_->isKeyPressed(k)) {
			std::cout << (short)k << " is pressed" << std::endl;
			for(auto &ctx: contexts_) {
				Action* a = nullptr;
				if(ctx->mapToAction(k, &a)) {
					actions.push_front(a);
					break;
				}
			}
		}
	});

	for(auto action = actions.rbegin(); action != actions.rend(); ++action) {
		for(auto listener = listeners_.rbegin(); listener != listeners_.rend(); ++listener) {
			if((*action)->dispatch((*listener).get())) { 
				break; }
		}
	}
}
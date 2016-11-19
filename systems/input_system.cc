#include "input_system.h"
#include <iostream>

using namespace std;

InputSystem::InputSystem(std::shared_ptr<Keyboard> kb): keyboard_{kb} {}

void InputSystem::registerContext(std::shared_ptr<Context> c) {
	contexts_.push_front(c);
}

void InputSystem::registerListener(std::shared_ptr<System> l) {
	listeners_.push_front(l);
}

void InputSystem::update(double delta) {

	keyboard_->update();

	// Map all keyboard input.
	std::list<Message*> messages;

	keyboard_->each([&](Keyboard::Key k) {
		if(keyboard_->pressedThisFrame(k) && !keyboard_->pressedLastFrame(k)) {
			for(auto &ctx: contexts_) {
				Action* a = nullptr;
				if(ctx->mapToAction(k, &a)) {
					messages.push_front(a);
					break;
				}
			}
		}

		bool released = keyboard_->pressedLastFrame(k) && keyboard_->releasedThisFrame(k);
		if(keyboard_->pressed(k) || released) {
			for(auto &ctx: contexts_) {
				State* s = nullptr;
				if(ctx->mapToState(k, &s)) {
					s->enabled = !released;
					messages.push_front(s);
					break;
				}
			}
		}
	});

	for(auto message = messages.rbegin(); message != messages.rend(); ++message) {
		for(auto listener = listeners_.rbegin(); listener != listeners_.rend(); ++listener) {
			if((*message)->dispatch((*listener).get())) { 
				break; }
		}
	}
}
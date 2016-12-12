#include "input_system.h"
#include <experimental/optional>

namespace asteroids {
namespace system {

using std::experimental::optional;
using message::Action;
using message::State;
using message::Message;
using input::Keyboard;
using input::Context;
using input::KeyboardKey;

InputSystem::InputSystem(Keyboard* kb): keyboard_{kb} {}

void InputSystem::pushContext(std::shared_ptr<Context> c) {
	contexts_.push(c);
}

void InputSystem::popContext() {
	contexts_.pop();
}

void InputSystem::registerListener(std::shared_ptr<System> l) {
	listeners_.push_back(l);
}

// Runs the input system:
// 1. Updates the keyboard.
// 2. Runs through each keyboard key and decides if
//    a key should be mapped to a state or action.
// 3. Performs all mappings and notifies all listeners.
void InputSystem::update(double delta) {

	// 1. Keyboard update.
	keyboard_->update();

	// We store all messages and process them once all
	// input is mapped.
	std::list<Message*> messages;

	if(contexts_.empty()) {
		return;
	}

	Context currentContext = *contexts_.top();

	// 2. Check each key
	keyboard_->each([&](KeyboardKey& k) {

		// If the key was just pressed, we try to map it to an action.
		if(keyboard_->firstPress(k)) {
			optional<Action*> a = currentContext.keyToAction(k);
			if(a) {
				messages.push_back(*a);
			}
		}

		// If the key is pressed or released, we try to map it to a state.
		// The enabled flag is used to tell listeners when a state is currently
		// active or has just ended.
		// Note that when firstPressed() is true, pressedAfterUpdate() is also
		// true. This means that if a key is mapped to a state and action, it will
		// trigger both when it's first pressed. This is done because we don't want to
		// wait a frame to decide if the key is being held and then enable the state.
		// TODO: Test waiting one frame to decide if key is being held before enabling state.
		if(keyboard_->pressedAfterUpdate(k) || keyboard_->released(k)) {
			optional<State*> s = currentContext.keyToState(k);
			if(s) {
				(*s)->enabled = !keyboard_->released(k);
				messages.push_front(*s);
			}
		}
	});

	// 3. Notify listeners
	for(auto& message: messages) {
		for(auto& listener: listeners_) {
			message->dispatch(listener.get());
		}
	}
}

} // system
} // asteroids

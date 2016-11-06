#include "keyboard.h"
#include <cstring>
#include <iostream>

auto keyToScancode(const Keyboard::Key key) {
	switch(key) {
		case(Keyboard::Key::A):
			return SDL_SCANCODE_A;
			break;
		default:
			return SDL_SCANCODE_UNKNOWN;
	}
}

SDLKeyboard::SDLKeyboard() {
	for(short i = (short)Keyboard::Key::FIRST; i <= (short)Keyboard::Key::LAST; ++i) {
		keyList_.push_back((Keyboard::Key)i);
	}
}

bool SDLKeyboard::update() {
	current_keystate_ = SDL_GetKeyboardState(nullptr);

	if(current_keystate_ == nullptr) return false;

	memcpy(&old_keystate_, current_keystate_, NUM_SCANCODES);

	return true;
}

bool SDLKeyboard::isKeyHeld(const Keyboard::Key k) {
	auto scancode = keyToScancode(k);
	return current_keystate_[scancode] && old_keystate_[scancode];
}

bool SDLKeyboard::isKeyPressed(const Keyboard::Key k) {
	auto scancode = keyToScancode(k);
	return current_keystate_[scancode];
}
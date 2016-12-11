#include "keyboard.h"
#include <cstring>
#include <iostream>

using namespace std;

auto keyToScancode(const Keyboard::Key key) {
	switch(key) {
		case(Keyboard::Key::A):
			return SDL_SCANCODE_A;
			break;
		case(Keyboard::Key::W):
			return SDL_SCANCODE_W;
			break;
		case(Keyboard::Key::S):
			return SDL_SCANCODE_S;
			break;
		case(Keyboard::Key::D):
			return SDL_SCANCODE_D;
			break;
		default:
			return SDL_SCANCODE_UNKNOWN;
	}
}

SDLKeyboard::SDLKeyboard() {
	memset(old_keystate_, 0, SDL_NUM_SCANCODES);
	memcpy(current_keystate_, SDL_GetKeyboardState(nullptr), SDL_NUM_SCANCODES);

	for(short i = (short)Keyboard::Key::FIRST; i <= (short)Keyboard::Key::LAST; ++i) {
		keyList_.push_back((Keyboard::Key)i);
	}
}

bool SDLKeyboard::update() {

	if(SDL_GetKeyboardState(nullptr) == nullptr) return false;

	memcpy(old_keystate_, current_keystate_, SDL_NUM_SCANCODES);
	memcpy(current_keystate_, SDL_GetKeyboardState(nullptr), SDL_NUM_SCANCODES);
	return true;
}

bool SDLKeyboard::pressedThisFrame(const Keyboard::Key k) {
	auto scancode = keyToScancode(k);
	return current_keystate_[scancode] && !old_keystate_[scancode];
}

bool SDLKeyboard::releasedThisFrame(const Keyboard::Key k) {
	auto scancode = keyToScancode(k);
	return !current_keystate_[scancode] && old_keystate_[scancode];
}

bool SDLKeyboard::pressed(const Keyboard::Key k) {
	auto scancode = keyToScancode(k);
	return current_keystate_[scancode];
}

bool SDLKeyboard::pressedLastFrame(const Keyboard::Key k) {
	auto scancode = keyToScancode(k);
	return old_keystate_[scancode];
}
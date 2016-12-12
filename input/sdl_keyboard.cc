#include "sdl_keyboard.h"
#include <cstring>

namespace asteroids {
namespace input {

auto keyToScancode(const KeyboardKey& key) {
	switch(key) {
		case(KeyboardKey::A):
			return SDL_SCANCODE_A;
		case(KeyboardKey::W):
			return SDL_SCANCODE_W;
		case(KeyboardKey::S):
			return SDL_SCANCODE_S;
		case(KeyboardKey::D):
			return SDL_SCANCODE_D;
		default:
			return SDL_SCANCODE_UNKNOWN;
	}
}

SDLKeyboard::SDLKeyboard() {
	memset(old_keystate_, 0, SDL_NUM_SCANCODES);
	memcpy(current_keystate_, SDL_GetKeyboardState(nullptr), SDL_NUM_SCANCODES);
}

bool SDLKeyboard::update() {

	if(SDL_GetKeyboardState(nullptr) == nullptr) return false;

	memcpy(old_keystate_, current_keystate_, SDL_NUM_SCANCODES);
	memcpy(current_keystate_, SDL_GetKeyboardState(nullptr), SDL_NUM_SCANCODES);
	return true;
}

bool SDLKeyboard::pressedAfterUpdate(const KeyboardKey& k) const {
	auto scancode = keyToScancode(k);
	return current_keystate_[scancode];
}

bool SDLKeyboard::pressedBeforeUpdate(const KeyboardKey& k) const {
	auto scancode = keyToScancode(k);
	return old_keystate_[scancode];
}

} // input
} // asteroids
/////////////////////////////////////////////////////////////////////////////////////////
// SDL Implementation of Keyboard abstract base class.
/////////////////////////////////////////////////////////////////////////////////////////
#ifndef INPUT_SDL_KEYBOARD_H
#define INPUT_SDL_KEYBOARD_H

#include "keyboard.h"
#include <SDL.h>

namespace asteroids {
namespace input {

class SDLKeyboard : public Keyboard {
public:

	SDLKeyboard();

	bool update() override;

	virtual bool pressedAfterUpdate(const KeyboardKey&) const override;
	virtual bool pressedBeforeUpdate(const KeyboardKey&) const override;

private:
	static constexpr uint32_t NUM_SCANCODES = SDL_NUM_SCANCODES;

	Uint8 current_keystate_[NUM_SCANCODES] = {0};
	Uint8 old_keystate_[NUM_SCANCODES] = {0};
	
};

} // input
} // asteroids



#endif //INPUT_SDL_KEYBOARD_H

#ifndef __KEYBOARD_H__
#define __KEYBOARD_H__

#include <SDL.h>
#include <cstdint>
#include <list>
#include <functional>

class Keyboard {
public:
	enum class Key : short {
		ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, ZERO, MINUS, EQUALS,
		Q, W, E, R, T, Y, U, I, O, P, RIGHTBRACKET, LEFTBRACKET, BACKSLASH,
		A, S, D, F, G, H, J, K, L, SEMICOLON, SINGLEQUOTE, ENTER,
		Z, X, C, V, B, N, M, COMMA, PEROID, FORWARDSLASH,

		// Don't use these please!
		FIRST = ONE,
		LAST = FORWARDSLASH,
	};

	virtual bool isKeyHeld(const Keyboard::Key) = 0;
	virtual bool isKeyPressed(const Keyboard::Key) = 0;
	virtual bool update() = 0;

	virtual void each(std::function<void(Keyboard::Key)>) = 0;
};

class SDLKeyboard : public Keyboard {
private:
	static constexpr uint32_t NUM_SCANCODES = SDL_NUM_SCANCODES;

	const uint8_t* current_keystate_ = nullptr;
	uint8_t old_keystate_[NUM_SCANCODES] = {false};

	std::list<Keyboard::Key> keyList_;

public:

	SDLKeyboard();

	bool update() override;
	bool isKeyHeld(const Keyboard::Key) override;
	bool isKeyPressed(const Keyboard::Key) override;

	void each(std::function<void(Keyboard::Key)> functor) override {
		for(auto &key: keyList_) {
			functor(key);
		}
	}

};
#endif
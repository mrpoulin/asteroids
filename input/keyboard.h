#ifndef __KEYBOARD_H__
#define __KEYBOARD_H__

#include <SDL.h>
#include <cstdint>
#include <list>
#include <functional>
#include <memory>

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

	virtual bool releasedThisFrame(const Keyboard::Key) = 0;
	virtual bool pressedThisFrame(const Keyboard::Key) = 0;
	virtual bool pressedLastFrame(const Keyboard::Key) = 0;
	virtual bool pressed(const Keyboard::Key) = 0;
	virtual bool update() = 0;

	virtual void each(std::function<void(Keyboard::Key)>) = 0;

	typedef std::shared_ptr<Keyboard> Ptr;
};

class SDLKeyboard : public Keyboard {
private:
	static constexpr uint32_t NUM_SCANCODES = SDL_NUM_SCANCODES;

	Uint8 current_keystate_[NUM_SCANCODES] = {0};
	Uint8 old_keystate_[NUM_SCANCODES] = {0};

	std::list<Keyboard::Key> keyList_;

public:

	SDLKeyboard();

	bool update() override;

	bool releasedThisFrame(const Keyboard::Key) override;
	bool pressedThisFrame(const Keyboard::Key) override;
	bool pressedLastFrame(const Keyboard::Key) override;
	bool pressed(const Keyboard::Key) override;

	void each(std::function<void(Keyboard::Key)> functor) override {
		for(auto &key: keyList_) {
			functor(key);
		}
	}
};
#endif
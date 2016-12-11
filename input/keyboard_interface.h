/////////////////////////////////////////////////////////////////////////////////////////
// 
/////////////////////////////////////////////////////////////////////////////////////////
#ifndef INPUT_KEYBOARD_INTERFACE_H
#define INPUT_KEYBOARD_INTERFACE_H

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

#endif //INPUT_KEYBOARD_INTERFACE_H
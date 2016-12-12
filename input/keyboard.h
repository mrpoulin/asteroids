/////////////////////////////////////////////////////////////////////////////////////////
// Abastract base class that defines how the game interacts with the keyboard.
/////////////////////////////////////////////////////////////////////////////////////////
#ifndef INPUT_KEYBOARD_H
#define INPUT_KEYBOARD_H

#include <functional>
#include <memory>
#include <array>

namespace asteroids {
namespace input {

enum class KeyboardKey {
	ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, ZERO, MINUS, EQUALS,
	Q, W, E, R, T, Y, U, I, O, P, RIGHTBRACKET, LEFTBRACKET, BACKSLASH,
	A, S, D, F, G, H, J, K, L, SEMICOLON, SINGLEQUOTE, ENTER,
	Z, X, C, V, B, N, M, COMMA, PEROID, FORWARDSLASH
};

//TODO: Change to std::array when all keys are added.
const std::array<KeyboardKey, 47> ALL_KEYS = {
	KeyboardKey::ONE, 
	KeyboardKey::TWO,
	KeyboardKey::THREE,
	KeyboardKey::FOUR,
	KeyboardKey::FIVE,
	KeyboardKey::SIX,
	KeyboardKey::SEVEN,
	KeyboardKey::EIGHT,
	KeyboardKey::NINE,
	KeyboardKey::ZERO,
	KeyboardKey::MINUS,
	KeyboardKey::EQUALS,
	KeyboardKey::Q,
	KeyboardKey::W,
	KeyboardKey::E,
	KeyboardKey::R,
	KeyboardKey::T,
	KeyboardKey::Y,
	KeyboardKey::U,
	KeyboardKey::I,
	KeyboardKey::O,
	KeyboardKey::P,
	KeyboardKey::RIGHTBRACKET,
	KeyboardKey::LEFTBRACKET,
	KeyboardKey::BACKSLASH,
	KeyboardKey::A,
	KeyboardKey::S,
	KeyboardKey::D,
	KeyboardKey::F, 
	KeyboardKey::G,
	KeyboardKey::H,
	KeyboardKey::J, 
	KeyboardKey::K, 
	KeyboardKey::L, 
	KeyboardKey::SEMICOLON,
	KeyboardKey::SINGLEQUOTE,
	KeyboardKey::ENTER,
	KeyboardKey::Z,
	KeyboardKey::X,
	KeyboardKey::C,
	KeyboardKey::V,
	KeyboardKey::B,
	KeyboardKey::N,
	KeyboardKey::M,
	KeyboardKey::COMMA,
	KeyboardKey::PEROID,
	KeyboardKey::FORWARDSLASH
};

class Keyboard {
public:
	// True if a key was active/pressed before the last update. 
	virtual bool pressedBeforeUpdate(const KeyboardKey&) const  = 0;

	// True if a key was active/pressed after the previous update.
	virtual bool pressedAfterUpdate(const KeyboardKey&) const = 0;

	// True if the key had been previously pressed & then released after
	// the last update.
	virtual bool released(const KeyboardKey& k) const {
		return !pressedAfterUpdate(k) && pressedBeforeUpdate(k);
	}

	// True if a key had not been previously pressed before the last update.
	virtual bool firstPress(const KeyboardKey& k) const {
		return pressedAfterUpdate(k) && !pressedBeforeUpdate(k);
	}

	// Handles updating the state of the keyboard.
	// Intended to be called each frame.
	virtual bool update() = 0;

	// Iterates over all the keys this keyboard manages &
	// invokes the supplied callback on each key.
	// TODO: Move implmentation of this to this class.
	virtual void each(std::function<void(KeyboardKey&)> f) const {
		for(auto key: ALL_KEYS) {
			f(key);
		}
	}

	virtual ~Keyboard() {}

	typedef std::shared_ptr<Keyboard> Ptr;
};

} // input
} // asteroids

#endif //INPUT_KEYBOARD_INTERFACE_H

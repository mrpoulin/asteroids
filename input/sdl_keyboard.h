/////////////////////////////////////////////////////////////////////////////////////////
// 
/////////////////////////////////////////////////////////////////////////////////////////
#ifndef INPUT_SDL_KEYBOARD_H
#define INPUT_SDL_KEYBOARD_H

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

#endif //INPUT_SDL_KEYBOARD_H
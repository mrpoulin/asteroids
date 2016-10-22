#ifndef __INPUT_MANAGER_HPP__
#define __INPUT_MANAGER_HPP__

#include "context.hpp"
#include "system.hpp"
#include "action.hpp"
#include "keyboard.hpp"
#include <memory>
#include <SDL.h>
#include <list>

class InputSystem : public System {
	private:
		std::list<std::shared_ptr<Context>> contexts_;
		std::list<std::shared_ptr<System>> listeners_;

		// Deivces
		std::shared_ptr<Keyboard> keyboard_;
	public:
		InputSystem(std::shared_ptr<EntityManager>, std::shared_ptr<Keyboard>);
		// TODO: Make more ... convinent
		void registerContext(std::shared_ptr<Context>);
		void registerListener(std::shared_ptr<System>);

		void update() override;
};


#endif

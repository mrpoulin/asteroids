#ifndef __INPUT_MANAGER_HPP__
#define __INPUT_MANAGER_HPP__

#include <memory>
#include <SDL.h>
#include <list>
#include "input/context.h"
#include "system.h"
#include "input/action.h"
#include "input/keyboard.h"
#include "entity/entity_manager.h"

class InputSystem : public System {
	private:
		std::list<std::shared_ptr<Context>> contexts_;
		std::list<std::shared_ptr<System>> listeners_;

		// Deivces
		std::shared_ptr<Keyboard> keyboard_;
	public:
		InputSystem(std::shared_ptr<Keyboard>);
		// TODO: Make more ... convinent
		void registerContext(std::shared_ptr<Context>);
		void registerListener(std::shared_ptr<System>);

		void update(double delta) override;
};


#endif

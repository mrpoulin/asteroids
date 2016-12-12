/////////////////////////////////////////////////////////////////////////////////////////
// The input system captures input from the keyboard and other devices,
// processes it, and sends out messages (actions or states) to other systems.
/////////////////////////////////////////////////////////////////////////////////////////
#ifndef SYSTEMS_INPUT_SYSTEM_H
#define SYSTEMS_INPUT_SYSTEM_H

#include <memory>
#include <list>
#include <stack>
#include "system.h"
#include "input/context.h"
#include "messages/action.h"
#include "messages/state.h"
#include "input/keyboard.h"

namespace asteroids {
namespace system {

class InputSystem : public System {
	private:
		std::stack<std::shared_ptr<input::Context>> contexts_;

		// Messages are always sent to each listener.
		std::list<std::shared_ptr<System>> listeners_;

		// ================== Devices ==================
		std::unique_ptr<input::Keyboard> keyboard_;

	public:
		InputSystem(input::Keyboard*);

		// Contexts are stored in a stack. The most recently
		// pushed context can map input to actions/states and 
		// all unmapped input is ignored.
		void pushContext(std::shared_ptr<input::Context>);
		void popContext();

		// Each listener registered will receive each mapped
		// action/state in a message.
		void registerListener(std::shared_ptr<System>);

		void update(double delta) override;
};

} // system
} // asteroids


#endif // SYSTEMS_INPUT_SYSTEM_H

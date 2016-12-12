/////////////////////////////////////////////////////////////////////////////////////////
// A context describes how input from input devices is mapped to actions and states
// that other systems understand.
/////////////////////////////////////////////////////////////////////////////////////////
#ifndef INPUT_CONTEXT_H
#define INPUT_CONTEXT_H

#include <unordered_map>
#include <utility>
#include <list>
#include <experimental/optional>
#include "messages/action.h"
#include "messages/state.h"
#include "keyboard.h"

namespace asteroids {
namespace input {

class Context {
public:

	typedef std::pair<KeyboardKey, message::Action*> ActionMapping;
	typedef std::pair<KeyboardKey, message::State*> StateMapping;

	typedef std::shared_ptr<Context> Ptr;

	// ============================ Actions ============================

	// Map an action to a keyboard key.
	// If a mapping already exists, it will be overwritten.
	// The class instance is returned to allow chaining.
	Context& addAction(const KeyboardKey& k, message::Action* a);

	// Define a lot of mappings at once using c++11 initialization
	// list syntax.
	void addActions(const std::list<ActionMapping> mappings);

	// Returns the action mapped to the given keyboard key.
	std::experimental::optional<message::Action*> keyToAction(const KeyboardKey& key);

	// ============================ States ==============================

	// Map a state to a keyboard key.
	// If a mapping already exists it will be overwritten
	Context& addState(const KeyboardKey& k, message::State* s);

	void addStates(const std::list<StateMapping> mappings);

	std::experimental::optional<message::State*> keyToState(const KeyboardKey& key);

private:
	// Keys that are not mapped are ignored.
	// It is possible to map the same key to an action and state. It is
	// up to the context creator to decide if this makes sense.
	std::unordered_map<KeyboardKey, message::Action*> actionMap_;
	std::unordered_map<KeyboardKey, message::State*> stateMap_;
};

} // input
} // asteroids

#endif // INPUT_CONTEXT_H

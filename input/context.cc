#include "context.h"

namespace asteroids {
namespace input {

using std::experimental::optional;
using message::Action;
using message::State;

Context& Context::addAction(const KeyboardKey& k, Action* a) {
    actionMap_[k] = a;
    return *this;
}

void Context::addActions(const std::list<ActionMapping> mappings) {
    for(auto& mapping: mappings) {
        addAction(mapping.first, mapping.second);
    }
}

optional<Action*> Context::keyToAction(const KeyboardKey& key) {
    auto it = actionMap_.find(key);
    if(it != actionMap_.end()) {
        return optional<Action*>(it->second);
    } else {
        return optional<Action*>();
    }
}

Context& Context::addState(const KeyboardKey& k, State* s) {
    stateMap_[k] = s;
    return *this;
}

void Context::addStates(const std::list<StateMapping> mappings) {
     for(auto& mapping: mappings) {
        addState(mapping.first, mapping.second);
    }
}

optional<State*> Context::keyToState(const KeyboardKey& key) {
    auto it = stateMap_.find(key);
    if(it != stateMap_.end()) {
        return optional<State*>(it->second);
    } else {
        return optional<State*>();
    }
}

}
}

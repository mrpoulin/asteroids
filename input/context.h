#ifndef __INPUT_MAPPER_HPP__
#define __INPUT_MAPPER_HPP__

#include <unordered_map>
#include "action.h"
#include "keyboard.h"

class Context {
	private:
		std::unordered_map<Keyboard::Key, Action*> actionMap_;
		std::unordered_map<Keyboard::Key, State*> stateMap_;
	public:

		void addAction(Keyboard::Key k, Action* a) {
			actionMap_[k] = a;
		}

		void addState(Keyboard::Key k, State* s) {
			stateMap_[k] = s;
		}

		bool mapToAction(Keyboard::Key key, Action** out) {
			auto it = actionMap_.find(key);
			if(it == actionMap_.end()) {
				return false;
			} else {
				*out = it->second;
				return true;
			}
		}

		bool mapToState(Keyboard::Key key, State** out) {
			auto it = stateMap_.find(key);
			if(it == stateMap_.end()) {
				return false;
			} else {
				*out = it->second;
				return true;
			}
		}

		typedef std::shared_ptr<Context> Ptr;
};

#endif

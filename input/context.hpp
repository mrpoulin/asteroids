#ifndef __INPUT_MAPPER_HPP__
#define __INPUT_MAPPER_HPP__

#include <unordered_map>
#include "action.hpp"
#include "keyboard.hpp"

class Context {
	private:
		std::unordered_map<Keyboard::Key, Action*> actionMap_;
	public:

		void addAction(Keyboard::Key k, Action* a) {
			actionMap_[k] = a;
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
};

#endif

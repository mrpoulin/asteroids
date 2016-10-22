#ifndef __ACTION_HPP__
#define __ACTION_HPP__

#include "message.hpp"

class Action : public Message {
};

class NullAction : public Action {
	inline virtual bool dispatch(MessageHandlerBase* h) override {
		return dynamicDispatch(h, *this);
	}
};

#endif

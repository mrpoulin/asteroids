#ifndef __ACTION_HPP__
#define __ACTION_HPP__

#include "message.h"
#include "entity_manager.h"
#include "vec2d.h"

class State: public Message {
public:
	State(bool e): enabled{e} {}
	State() = default;

	bool enabled;
};

class Action: public Message {
};

class AccelerateState: public State {
public:
	AccelerateState(Entity e, float a): entity{e}, acceleration{a} {}
	inline virtual bool dispatch(MessageHandlerBase* h) override {
		return dynamicDispatch(h, *this);
	}

	Entity entity;
	float acceleration;
};

class RotateState: public State {
public:
	RotateState(Entity e, float degrees): entity{e}, degrees{degrees} {}

	inline virtual bool dispatch(MessageHandlerBase* h) override {
		return dynamicDispatch(h, *this);
	}

	Entity entity;
	float degrees;
};

#endif

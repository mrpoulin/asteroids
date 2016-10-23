#ifndef __MESSAGE_HPP__
#define __MESSAGE_HPP__

#include <memory>
#include "vec2d.hpp"
#include "game_types.hpp"

class MessageHandlerBase {
public:
	virtual ~MessageHandlerBase() {}
};

template <typename T>
class MessageHandler : public MessageHandlerBase {
	public:
		virtual bool handle(T&) = 0;
};

template <typename T>
bool dynamicDispatch(MessageHandlerBase* h, T& message) {
	MessageHandler<T>* handler =  dynamic_cast<MessageHandler<T>*>(h);

	if(!handler) return false;

	return handler->handle(message);
}

class Message {
	public:
		virtual bool dispatch(MessageHandlerBase*) = 0;
};

class GetScreenPositionMessage : public Message {
	public:
		Vec2D<Position> position;
		inline virtual bool dispatch(MessageHandlerBase* h) override {
			return dynamicDispatch(h, *this);
		}
};

class SetScreenPositionMessage : public Message {
	public:
		Vec2D<Position> position;
		inline virtual bool dispatch(MessageHandlerBase* h) override {
			return dynamicDispatch(h, *this);
		}
};


#endif


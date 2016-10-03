#ifndef __MESSAGE_HPP__
#define __MESSAGE_HPP__

#include <memory>
#include "vec2d.hpp"


class MessageHandlerBase {};

template <typename T>
class MessageHandler : public MessageHandlerBase {
	public:
		virtual void handle(T&) = 0;
};

template <typename T>
void dynamicDispatch(MessageHandlerBase* h, T& message) {
	static_cast< MessageHandler<T>*>(h)->handle(message);
}

class Message {
	public:
		virtual void dispatch(MessageHandlerBase*) = 0;
};

class GetScreenPositionMessage : public Message {
	public:
		Vec2D<float> position;
		inline virtual void dispatch(MessageHandlerBase* h) {
			dynamicDispatch(h, *this);
		}
};

class SetScreenPositionMessage : public Message {
	public:
		Vec2D<float> position;
		inline virtual void dispatch(MessageHandlerBase* h) {
			dynamicDispatch(h, *this);
		}
};


#endif


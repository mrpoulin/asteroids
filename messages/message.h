/////////////////////////////////////////////////////////////////////////////////////////
// Common code for creating message handlers. Also defines code for creating
// Messages
/////////////////////////////////////////////////////////////////////////////////////////

#ifndef MESSAGES_MESSAGE_H
#define MESSAGES_MESSAGE_H

#include <string>
#include "common/vec2d.h"
#include "common/game_types.h"

namespace asteroids {
namespace message {

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

#define SetScreenPosition_MESSAGE(decl) \
	decl(Vec2D<ScreenPosition>, position)

#define GetScreenPosition_MESSAGE(decl) \
	decl(Vec2D<ScreenPosition>, position)

#define SetSpriteSequence_MESSAGE(decl) \
	decl(std::string, newKey)

#define ALL_MESSAGES \
	CREATE_MESSAGE(GetScreenPosition) \
	CREATE_MESSAGE(SetScreenPosition) \
	CREATE_MESSAGE(SetSpriteSequence)

#define DECL(T, n) T n;
#define CREATE_MESSAGE(NAME) \
	class NAME##Message : public Message { \
	public: \
		NAME##_MESSAGE(DECL) \
		inline virtual bool dispatch(MessageHandlerBase *h) override { \
			return dynamicDispatch(h, *this); \
		} \
	};

ALL_MESSAGES

#undef CREATE_MESSAGE
#undef ALL_MESSAGES
#undef DECL

} // asteroids
} // message


#endif // MESSAGES_MESSAGE_H


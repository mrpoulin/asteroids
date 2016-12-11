/////////////////////////////////////////////////////////////////////////////////////////
// Code for creating Actions.
// Actions represent one time events triggered by a key press.
/////////////////////////////////////////////////////////////////////////////////////////

#ifndef MESSAGES_ACTION_H
#define MESSAGES_ACTION_H

namespace asteroids {
namespace messages {

#define ALL_ACTIONS

#define DECL(T, n) T n;
#define CREATE_ACTION(NAME) \
	class NAME##Action : public Message { \
	public: \
		NAME##_ACTION(DECL) \
		inline virtual bool dispatch(MessageHandlerBase *h) override { \
			return dynamicDispatch(h, *this); \
		} \
	};

ALL_ACTIONS

#undef CREATE_ACTION
#undef DECL
#undef ALL_ACTIONS

} // messages
} // asteroids

#endif // MESSAGES_ACTION_H
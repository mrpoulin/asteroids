/////////////////////////////////////////////////////////////////////////////////////////
// Code for creating States.
// States represent a press and hold of a keyboard key.
/////////////////////////////////////////////////////////////////////////////////////////
#ifndef MESSAGES_STATE_H
#define MESSAGES_STATE_H

#include "common/game_types.h"

namespace asteroids {
namespace messages {

#define DECL(T, n) T n;

#define Accelerate_STATE \
    DECL(common::LogicalPosition accleration) \
    DECL(entity::Entity entity)

#define Rotate_STATE \
    DECL(common::LogicalPosition rotation) \
    DECL(entity::Entity entity)

#define ALL_STATES \
    CREATE_STATE(Accelerate) \
    CREATE_STATE(Rotate)

#define CREATE_STATE(NAME) \
	class NAME##State : public Message { \
	public: \
        bool enabled; \
        NAME##State() = default; \
        NAME##State(bool e): enabled{e} {} \
		NAME##_STATE(DECL) \
		inline virtual bool dispatch(MessageHandlerBase *h) override { \
			return dynamicDispatch(h, *this); \
		} \
	};

ALL_STATES

#undef CREATE_STATE
#undef DECL
#undef ALL_STATES

} // messages
} // asteroids

#endif // MESSAGES_STATE_H
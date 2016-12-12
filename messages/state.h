/////////////////////////////////////////////////////////////////////////////////////////
// Code for creating States.
// States represent a press and hold of a keyboard key.
/////////////////////////////////////////////////////////////////////////////////////////
#ifndef MESSAGES_STATE_H
#define MESSAGES_STATE_H

#include "common/game_types.h"
#include "message.h"
#include "entity/entity.h"

namespace asteroids {
namespace message {

class State : public Message {
public:
    bool enabled;
    State(bool e): enabled{e} {}
};

#define Accelerate_STATE(decl) \
    decl(common::LogicalQuantity, acceleration) \
    decl(entity::Entity, entity)

#define Rotate_STATE(decl) \
    decl(common::LogicalQuantity, rotation) \
    decl(entity::Entity, entity)

#define ALL_STATES \
    CREATE_STATE(Accelerate) \
    CREATE_STATE(Rotate)

#define DECL(T, n) T n;
#define CREATE_STATE(NAME) \
	class NAME##State : public State { \
	public: \
        bool enabled; \
        NAME##State() = default; \
        NAME##State(bool e): State{e} {} \
		NAME##_STATE(DECL) \
		inline virtual bool dispatch(MessageHandlerBase *h) override { \
			return dynamicDispatch(h, *this); \
		} \
	};

ALL_STATES

#undef CREATE_STATE
#undef DECL
#undef ALL_STATES

} // message
} // asteroids

#endif // MESSAGES_STATE_H

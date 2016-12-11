/////////////////////////////////////////////////////////////////////////////////////////
// Stores the logical position of an entity. The logical position is used in physics
// and collision detection.
/////////////////////////////////////////////////////////////////////////////////////////

#ifndef COMPONENT_LOGICAL_POSITION_COMPONENT_H
#define COMPONENT_LOGICAL_POSITION_COMPONENT_H

#include "component.h"
#include "common/vec2d.h"
#include "messages/message.h"
#include "common/game_types.h"

namespace asteroids {
namespace component {

class LogicalPositionComponent : public Component, 
	public message::MessageHandler<GetScreenPositionMessage>,
	public message::MessageHandler<SetScreenPositionMessage>  
{
	public:
		common::Vec2D<LogicalPosition> position;
		
		LogicalPositionComponent() = default;
		LogicalPositionComponent(const common::Vec2D<LogicalPosition>& startingPosition): position{startingPosition} {}
};

} // asteroids
} // component


#endif // COMPONENT_LOGICAL_POSITION_COMPONENT_H

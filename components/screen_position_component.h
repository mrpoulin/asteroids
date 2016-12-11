/////////////////////////////////////////////////////////////////////////////////////////
// Stores the position of an entity on the screen in screen coordiantes.
/////////////////////////////////////////////////////////////////////////////////////////

#ifndef COMPONENT_SCREEN_POSITION_COMPONENT_H
#define COMPONENT_SCREEN_POSITION_COMPONENT_H

#include "component.h"
#include "common/vec2d.h"
#include "messages/message.h"
#include "common/game_types.h"

namespace asteroids {
namespace component {

class ScreenPositionComponent : public Component, 
	public message::MessageHandler<GetScreenPositionMessage>,
	public message::MessageHandler<SetScreenPositionMessage>  
{
	public:
		common::Vec2D<ScreenPosition> position;
		
		ScreenPositionComponent() = default;
		ScreenPositionComponent(const common::Vec2D<ScreenPosition>& startingPosition): position{startingPosition} {}

		bool handle(message::GetScreenPositionMessage& msg);
		bool handle(message::SetScreenPositionMessage& msg);
};

} // asteroids
} // component


#endif // COMPONENT_SCREEN_POSITION_COMPONENT_H

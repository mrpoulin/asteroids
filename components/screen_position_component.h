#ifndef __SCREEN_POSITION_COMPONENT_HPP__
#define __SCREEN_POSITION_COMPONENT_HPP__

#include "component.h"
#include "vec2d.h"
#include "message.h"
#include "game_types.h"

class ScreenPositionComponent : public Component, 
	public MessageHandler<GetScreenPositionMessage>,
	public MessageHandler<SetScreenPositionMessage>  
{
	public:
		Vec2D<float> position;
		
		ScreenPositionComponent() = default;
		ScreenPositionComponent(const Vec2D<float>& startingPosition): position{startingPosition} {}

		bool handle(GetScreenPositionMessage& msg);
		bool handle(SetScreenPositionMessage& msg);
};


#endif

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
	private:
		Vec2D<Position> position_;
	public:
		ScreenPositionComponent(): position_{0, 0} {}
		ScreenPositionComponent(const Vec2D<Position>& startingPosition): position_{startingPosition} {}

		Vec2D<Position> position() { return position_; }

		bool handle(GetScreenPositionMessage& msg);
		bool handle(SetScreenPositionMessage& msg);

};


#endif

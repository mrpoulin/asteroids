#ifndef __SCREEN_POSITION_COMPONENT_HPP__
#define __SCREEN_POSITION_COMPONENT_HPP__

#include "component.hpp"
#include "vec2d.hpp"
#include "message.hpp"
#include "game_types.hpp"

class ScreenPositionComponent : public Component, 
	public MessageHandler<GetScreenPositionMessage>,
	public MessageHandler<SetScreenPositionMessage>  
{
	private:
		Vec2D<Position> position_;
	public:
		ScreenPositionComponent(): position_{0, 0} {}
		ScreenPositionComponent(const Vec2D<Position>& startingPosition): position_{startingPosition} {}

		bool handle(GetScreenPositionMessage& msg);
		bool handle(SetScreenPositionMessage& msg);

};


#endif

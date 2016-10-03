#ifndef __SCREEN_POSITION_COMPONENT_HPP__
#define __SCREEN_POSITION_COMPONENT_HPP__

#include "component.hpp"
#include "vec2d.hpp"
#include "message.hpp"

class ScreenPositionComponent : public Component, 
	MessageHandler<GetScreenPositionMessage>,
	MessageHandler<SetScreenPositionMessage>  
{
	private:
		Vec2D<float> position_;
	public:
		ScreenPositionComponent(): position_{0, 0} {}
		ScreenPositionComponent(const Vec2D<float>& startingPosition): position_{startingPosition} {}

		void handle(GetScreenPositionMessage& msg);
		void handle(SetScreenPositionMessage& msg);

};


#endif

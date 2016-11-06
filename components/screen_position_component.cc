#include "screen_position_component.h"

bool ScreenPositionComponent::handle(GetScreenPositionMessage& msg) {
	msg.position = position_;
	return true;
}

bool ScreenPositionComponent::handle(SetScreenPositionMessage& msg) {
	position_ = msg.position;
	return true;
}
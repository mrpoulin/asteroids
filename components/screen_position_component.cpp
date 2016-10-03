#include "screen_position_component.hpp"

void ScreenPositionComponent::handle(GetScreenPositionMessage& msg) {
	msg.position = position_;
}

void ScreenPositionComponent::handle(SetScreenPositionMessage& msg) {
	position_ = msg.position;
}

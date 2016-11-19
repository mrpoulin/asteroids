#include "screen_position_component.h"

bool ScreenPositionComponent::handle(GetScreenPositionMessage& msg) {
	msg.position = position;
	return true;
}

bool ScreenPositionComponent::handle(SetScreenPositionMessage& msg) {
	position = msg.position;
	return true;
}

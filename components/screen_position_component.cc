#include "screen_position_component.h"

namespace asteroids {
namespace component {

bool ScreenPositionComponent::handle(message::GetScreenPositionMessage& msg) {
	msg.position = position;
	return true;
}

bool ScreenPositionComponent::handle(message::SetScreenPositionMessage& msg) {
	position = msg.position;
	return true;
}

} // component
} // asteroids

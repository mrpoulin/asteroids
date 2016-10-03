#include <iostream>
#include "message.hpp"
#include "screen_position_component.hpp"

int main() {

	ScreenPositionComponent p;
	GetScreenPositionMessage m;
	SetScreenPositionMessage m2;

	m2.position = Vec2D<float>(4,4);

	p.handle(m2);
	p.handle(m);
	std::cout << m.position.x << " " << m.position.y << std::endl;

	
	return 0;
}

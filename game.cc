#include <iostream>
#include <memory>
#include "engine.h"
#include "rendering_system.h"
#include "action.h"
#include "test_system.h"
#include "screen_position_component.h"
#include "sprite_component.h"

int main() {

	Engine engine;

	auto testSystem = std::shared_ptr<TestSystem>(new TestSystem());

	auto basicContext = std::shared_ptr<Context>(new Context());
	basicContext->addAction(Keyboard::Key::A, new NullAction());

	engine.addInputListener(testSystem);
	engine.addContext(basicContext);
	
	auto shipTexture = engine.getTexture("../assets/sprites/ship.png");

	auto screenPosComp = std::shared_ptr<ScreenPositionComponent>(new ScreenPositionComponent());
	auto spriteComp = std::shared_ptr<SpriteComponent>(new SpriteComponent(shipTexture, 92, 92, 0, 0));

	auto shipEntity = engine.createEntity({screenPosComp, spriteComp});

	engine.run();
	return 0;
}

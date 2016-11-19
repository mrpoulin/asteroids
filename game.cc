#include <iostream>
#include <memory>
#include "engine.h"
#include "rendering_system.h"
#include "action.h"
#include "movement_system.h"
#include "screen_position_component.h"
#include "sprite_component.h"
#include "physics_component.h"
#include "physics_system.h"

int main() {

	EntityManager::Ptr em = EntityManager::Ptr(new EntityManager());
	Engine engine(em);

	// Setup systems.
	auto physicsSystem = std::shared_ptr<PhysicsSystem>(new PhysicsSystem(em));
	auto movementSystem = std::shared_ptr<MovementSystem>(new MovementSystem(em));
	engine.addSystem(physicsSystem);
	engine.addInputListener(physicsSystem);

	
	// Create Ship.
	auto shipTexture = engine.getTexture("../assets/sprites/ship.png");
	auto screenPosComp = std::shared_ptr<ScreenPositionComponent>(new ScreenPositionComponent());
	auto spriteComp = std::shared_ptr<SpriteComponent>(new SpriteComponent(shipTexture, 84, 87, 289, 0));
	auto physicsComp = std::shared_ptr<PhysicsComponent>(new PhysicsComponent(3, 5, 1));
	auto shipEntity = engine.createEntity({screenPosComp, spriteComp, physicsComp});

	// Setup input.
	auto firstPlayerContext = std::shared_ptr<Context>(new Context());
	firstPlayerContext->addState(Keyboard::Key::W, new AccelerateState(shipEntity, 1.5));
	firstPlayerContext->addState(Keyboard::Key::S, new AccelerateState(shipEntity, -1.5));
	firstPlayerContext->addState(Keyboard::Key::A, new RotateState(shipEntity, -0.45));
	firstPlayerContext->addState(Keyboard::Key::D, new RotateState(shipEntity, 0.45));

	engine.addContext(firstPlayerContext);

	engine.run();
	return 0;
}

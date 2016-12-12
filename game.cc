#include <iostream>
#include <memory>
#include "engine/engine.h"
#include "systems/rendering_system.h"
#include "messages/action.h"
#include "components/screen_position_component.h"
#include "components/sprite_component.h"
#include "components/physics_component.h"
#include "systems/physics_system.h"

int main() {

	// EntityManager::Ptr em = EntityManager::Ptr(new EntityManager());
	// Engine engine(em);

	// // Setup systems.
	// auto physicsSystem = std::shared_ptr<PhysicsSystem>(new PhysicsSystem(em));
	// auto movementSystem = std::shared_ptr<MovementSystem>(new MovementSystem(em));
	// engine.addSystem(physicsSystem);
	// engine.addInputListener(physicsSystem);

	
	// // Create Ship.
	// auto shipTexture = engine.getTexture("../assets/sprites/ship.png");
	// auto screenPosComp = std::shared_ptr<ScreenPositionComponent>(new ScreenPositionComponent());

	// auto spriteComp = std::shared_ptr<AnimatedSpriteComponent>(new AnimatedSpriteComponent(shipTexture, "stationary"));
	// spriteComp->addFrameTo("stationary", {51, 52, 0, 0});

	// auto physicsComp = std::shared_ptr<PhysicsComponent>(new PhysicsComponent(1.3, 3, 1));
	// auto shipEntity = engine.createEntity({screenPosComp, spriteComp, physicsComp});

	// // Setup input.
	// auto firstPlayerContext = std::shared_ptr<Context>(new Context());
	// firstPlayerContext->addState(Keyboard::Key::W, new AccelerateState(shipEntity, 1.1));
	// firstPlayerContext->addState(Keyboard::Key::S, new AccelerateState(shipEntity, -1.1));
	// firstPlayerContext->addState(Keyboard::Key::A, new RotateState(shipEntity, -0.3));
	// firstPlayerContext->addState(Keyboard::Key::D, new RotateState(shipEntity, 0.3));

	// engine.addContext(firstPlayerContext);

	// engine.run();
	return 0;
}

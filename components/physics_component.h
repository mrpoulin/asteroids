/////////////////////////////////////////////////////////////////////////////////////////
// The physics component stores all physics related data (speed, velocity, rotation)
// that an entity requires to move.
/////////////////////////////////////////////////////////////////////////////////////////

#ifndef COMPONENT_PHYSICS_COMPONENT_H
#define COMPONENT_PHYSICS_COMPONENT_H

#include "component.h"
#include "common/rotation2d.h"
#include "common/game_types.h"

namespace asteroids {
namespace component {

class PhysicsComponent : public Component {
public:

    common::LogicalQuantity maxSpeed;
    common::LogicalQuantity maxAcceleration;
    // Constant force applied in the opposite direction of velocity.
    common::LogicalQuantity friction;

    common::Vec2D<common::LogicalQuantity> velocity;
    common::Rotation2D<common::LogicalQuantity> rotation;
    common::LogicalQuantity acceleration;

    PhysicsComponent() = default;
    PhysicsComponent(common::LogicalQuantity maxSpeed,
        common::LogicalQuantity maxAcceleration,
        common::LogicalQuantity friction): 
        maxSpeed{maxSpeed}, maxAcceleration{maxAcceleration}, friction{friction},
        rotation{0}, acceleration{0} {}
};

} // component
} // asteroids

#endif // COMPONENT_PHYSICS_COMPONENT_H

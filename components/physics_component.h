/////////////////////////////////////////////////////////////////////////////////////////
// The physics component stores all physics related data (speed, velocity, rotation)
// that an entity requires to move.
/////////////////////////////////////////////////////////////////////////////////////////

#ifndef COMPONENT_PHYSICS_COMPONENT_H
#define COMPONENT_PHYSICS_COMPONENT_H

#include "component.h"

namespace asteroids {
namespace component {

class PhysicsComponent : public Component {
public:

    float acceleration;
    common::Vec2D<float> velocity;
    common::Rotation2D rotation;

    float maxSpeed;
    float maxAcceleration;

    // Constant force applied in the opposite direction of velocity.
    float friction;

    PhysicsComponent() = default;
    PhysicsComponent(float maxSpeed, float maxAcceleration, float friction): 
        maxSpeed{maxSpeed}, maxAcceleration{maxAcceleration}, friction{friction},
        rotation_{0}, acceleration{0} {}
};

} // component
} // asteroids

#endif // COMPONENT_PHYSICS_COMPONENT_H
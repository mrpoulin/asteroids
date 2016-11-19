#ifndef __PHYSICS_COMPONENT_H__
#define __PHYSICS_COMPONENT_H__

#include "component.h"
#include <cmath>

class PhysicsComponent : public Component {
public:
    PhysicsComponent() = default;
    PhysicsComponent(float maxSpeed, float maxAcceleration, float friction): 
        maxSpeed_{maxSpeed}, maxAcceleration_{maxAcceleration}, friction_{friction},
        rotation_{0}, acceleration{0} {}

    static constexpr float PI = 3.14159265359;
    static constexpr float DEGREE_TO_RAD = PI / (double)180;

    float acceleration;
    Vec2D<float> velocity;

    float maxSpeed() { return maxSpeed_; }
    float maxAcceleration() { return maxAcceleration_; }
    float friction() { return friction_; }
    float rotation() { return rotation_; }

    inline void rotate(float degreesAmount) {
        rotation_ += degreesAmount;
        rotation_ = modAngle(rotation_);
    }

    inline void rotation(float degrees) {
        rotation_ = degrees;
        rotation_ = modAngle(rotation_);

    }

    inline Vec2D<float> rotationVector() {
        float rad = rotation_ * DEGREE_TO_RAD;
        return {std::cos(rad), std::sin(rad)};
    }

    private:
        float rotation_;
        float maxSpeed_;
        float maxAcceleration_;
        float friction_;

        float modAngle(double angle) {
            return angle - 360 * floor(angle / 360); 
        }
}; 

#endif
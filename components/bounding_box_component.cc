#include "bounding_box_component.h"

namespace asteroids {
namespace component {

BoundingBoxComponent::BoundingBoxComponent(float x, float y, float w, float h):
    upperLeftHand_{x, y}, width_{w}, height_{h}
{
}

BoundingBoxComponent::BoundingBoxComponent(common::Vec2D<float>& pos, float w, float h):
    upperLeftHand_{pos}, width_{w}, height_{h}
{
}

bool BoundingBoxComponent::handle(message::SetScreenPositionMessage& msg) {
    return true;
}

} // component
} // asteroids

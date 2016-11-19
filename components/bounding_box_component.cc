#include "bounding_box_component.h"

BoundingBoxComponent::BoundingBoxComponent(float x, float y, float w, float h):
    upperLeftHand_{x, y}, width_{w}, height_{h}
{
}

BoundingBoxComponent::BoundingBoxComponent(Vec2D<float>& pos, float w, float h):
    upperLeftHand_{pos}, width_{w}, height_{h}
{
}

bool BoundingBoxComponent::handle(SetScreenPositionMessage& msg) {
    upperLeftHand_ = msg.position;
    return true;
}
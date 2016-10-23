#include "bounding_box_component.hpp"

BoundingBoxComponent::BoundingBoxComponent(Position x, Position y, Dimension w, Dimension h):
    upperLeftHand_{x, y}, width_{w}, height_{h}
{
}

BoundingBoxComponent::BoundingBoxComponent(Vec2D<Position>& pos, Dimension w, Dimension h):
    upperLeftHand_{pos}, width_{w}, height_{h}
{
}

bool BoundingBoxComponent::handle(SetScreenPositionMessage& msg) {
    upperLeftHand_ = msg.position;
    return true;
}
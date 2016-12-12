/////////////////////////////////////////////////////////////////////////////////////////
//   Bounding box component for collision detection.
/////////////////////////////////////////////////////////////////////////////////////////

#ifndef COMPONENTS_BOUNDING_BOX_COMPONENT_H
#define COMPONENTS_BOUNDING_BOX_COMPONENT_H

#include "component.h"
#include "messages/message.h"
#include "common/vec2d.h"
#include "common/game_types.h"

namespace asteroids {
namespace component {

class BoundingBoxComponent : public Component,
                             public message::MessageHandler<message::SetScreenPositionMessage> 
{
public:
    BoundingBoxComponent(float x, float y, float w, float h);
    BoundingBoxComponent(common::Vec2D<float>& pos, float w, float h);

    bool handle(message::SetScreenPositionMessage& msg);

private:
    common::Vec2D<float> upperLeftHand_;
    float width_, height_;
};

} // component
} // asteroids

#endif // COMPONENTS_BOUNDING_BOX_COMPONENT_H

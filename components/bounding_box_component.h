#ifndef __BOUNDING_BOX_COMPONENT_HPP__
#define __BOUNDING_BOX_COMPONENT_HPP__

#include "component.h"
#include "message.h"
#include "vec2d.h"
#include "game_types.h"

class BoundingBoxComponent : public Component,
                             public MessageHandler<SetScreenPositionMessage> 

{
    private:
        Vec2D<float> upperLeftHand_;
        float width_, height_;
    public:
        BoundingBoxComponent(float x, float y, float w, float h);
        BoundingBoxComponent(Vec2D<float>& pos, float w, float h);

        bool handle(SetScreenPositionMessage& msg);
};

#endif
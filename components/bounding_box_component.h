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
        Vec2D<Position> upperLeftHand_;
        Dimension width_, height_;
    public:
        BoundingBoxComponent(Position x, Position y, Dimension w, Dimension h);
        BoundingBoxComponent(Vec2D<Position>& pos, Dimension w, Dimension h);

        bool handle(SetScreenPositionMessage& msg);
};

#endif
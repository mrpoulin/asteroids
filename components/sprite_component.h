#ifndef __SPRITE_COMPONENT_HPP__
#define __SPRITE_COMPONENT_HPP__

#include <memory>
#include "component.h"
#include "game_types.h"
#include "renderable.h"

class SpriteComponent : public Component {
    private:
        Dimension width_, height_;
        Position x_, y_;
        RenderableInterface::Ptr renderable_;
    public:

        SpriteComponent(RenderableInterface::Ptr r, Dimension width, Dimension height,
                        Position x, Position y):
            renderable_{r}, width_{width}, height_{height}, x_{x}, y_{y} {}

        Dimension width() const { return width_; }
        Dimension height() const { return height_; }
        Position x() const { return x_; }
        Position y() const { return y_; }

        RenderableInterface::Ptr renderable() const { return renderable_; }
};

#endif

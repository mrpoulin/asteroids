#ifndef __RENDERING_COMPONENT_HPP__
#define __RENDERING_COMPONENT_HPP__

#include <memory>
#include "component.hpp"
#include "game_types.hpp"
#include "renderable.hpp"

class RenderingComponent : public Component {
    private:
        Dimension width_, height_
        std::shared_ptr<RenderableInterface> renderable_;
    public:
        Dimension width() const { return width_; }
        Dimension height() const { return height_; }

        std::shared_ptr<RenderableInterface> renderable() const { return renderable_; }
};

#endif

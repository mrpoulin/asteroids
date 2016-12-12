/////////////////////////////////////////////////////////////////////////////////////////
// Any type that implements this interface must be able to render itself
// using SDL.
/////////////////////////////////////////////////////////////////////////////////////////

#ifndef GRAPHICS_RENDERABLE_H
#define GRAPHICS_RENDERABLE_H

#include <SDL.h>
#include <memory>
#include "common/vec2d.h"
#include "common/game_types.h"

namespace asteroids {
namespace graphics {

class Renderable {
public:
    virtual bool render(SDL_Renderer*, const SDL_Rect& src, const SDL_Rect& dest, 
                        const float angle, const common::Vec2D<common::ScreenPosition> center, SDL_RendererFlip flip = SDL_FLIP_NONE) = 0;

    typedef std::shared_ptr<Renderable> Ptr;

    virtual ~Renderable() {}
};

} // graphics
} // asteroids

#endif // GRAPHICS_RENDERABLE_H

#ifndef __RENDERABLE_HPP__
#define __RENDERABLE_HPP__

#include <SDL.h>
#include <memory>
#include "vec2d.h"

class RenderableInterface {
    public:
        virtual bool render(SDL_Renderer*, const SDL_Rect& src, const SDL_Rect& dest, 
                            const float angle, const Vec2D<float> center, SDL_RendererFlip flip = SDL_FLIP_NONE) = 0;

        typedef std::shared_ptr<RenderableInterface> Ptr; 

};

#endif
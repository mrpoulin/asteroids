#ifndef __RENDERABLE_HPP__
#define __RENDERABLE_HPP__

#include <SDL.h>
#include <memory>

class RenderableInterface {
    public:
        virtual bool render(SDL_Renderer*, const SDL_Rect& src, const SDL_Rect& dest) = 0;

        typedef std::shared_ptr<RenderableInterface> Ptr; 

};

#endif
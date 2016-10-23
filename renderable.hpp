#ifndef __RENDERABLE_HPP__
#define __RENDERABLE_HPP__

#include <SDL.h>

class RenderableInterface {
    public:
        bool render(SDL_Renderer*, const SDL_Rect&, const SDL_Rect&);

};

#endif
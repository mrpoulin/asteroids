#ifndef __TEXTURE_HPP__
#define __TEXTURE_HPP__

#include <SDL.h>
#include <string>
#include "renderable.h"
#include "game_types.h"

class Texture : public RenderableInterface
{
  public:
    SDL_Texture *texture_;
    Texture(SDL_Texture*);

    Dimension width() const;
    Dimension height() const;

    bool render(SDL_Renderer*, const SDL_Rect& src, const SDL_Rect& dest) override;
    virtual ~Texture();

    typedef std::shared_ptr<Texture> Ptr;
};

#endif
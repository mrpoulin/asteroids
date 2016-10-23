#ifndef __TEXTURE_HPP__
#define __TEXTURE_HPP__

#include <SDL.h>
#include <string>
#include "renderable.hpp"

class Texture : public RenderableInterface
{
  private:
    SDL_Texture *texture_;

  public:
    Texture(SDL_Texture *);

    Dimension width() const;
    Dimension height() const;

    bool render(SDL_Renderer *, const SDL_Rect &, const SDL_Rect &) override;
    virtual ~Texture();

    typedef std::shared_ptr<Texture> Ptr;
};

#endif
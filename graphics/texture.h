/////////////////////////////////////////////////////////////////////////////////////////
// Wraps an SDL texture object. 
/////////////////////////////////////////////////////////////////////////////////////////

#ifndef GRAPHICS_TEXTURE_H
#define GRAPHICS_TEXTURE_H

#include <SDL.h>
#include <string>
#include "renderable.h"
#include "common/game_types.h"

namespace asteroids {
namespace graphics {

class Texture : public Renderable
{
public:
  SDL_Texture *texture_;
  Texture(SDL_Texture*);

  // Dimension width() const;
  // Dimension height() const;

  bool render(SDL_Renderer*, const SDL_Rect& src, const SDL_Rect& des,
              const float angle, const common::Vec2D<common::ScreenPosition> center, SDL_RendererFlip flip = SDL_FLIP_NONE) override;
  virtual ~Texture();

  typedef std::shared_ptr<Texture> Ptr;
};

} // graphics
} // asteroids

#endif // GRAPHICS_TEXTURE_H

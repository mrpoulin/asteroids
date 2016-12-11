#include "texture.h"

namespace asteroids {
namespace graphics {

 Texture::Texture(SDL_Texture* tex):
    texture_{tex}
{
}

bool Texture::render(SDL_Renderer* renderer, const SDL_Rect& src, const SDL_Rect& dest,
                     const float angle, const common::Vec2D<ScreenPosition> center, SDL_RendererFlip flip) {

    SDL_Point point = {center.x, center.y};

    if(SDL_RenderCopyEx(renderer, texture_, &src, &dest, angle, &point, flip) < 0) {
        return false;
    }

    return true;
}

Texture::~Texture() {
    if(texture_) {
        SDL_DestroyTexture(texture_);
    }
}

} // graphics
} // asteroids
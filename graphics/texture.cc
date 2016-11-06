#include "texture.h"
#include <iostream>

using namespace std;

 Texture::Texture(SDL_Texture* tex):
    texture_{tex}
{
}

bool Texture::render(SDL_Renderer* renderer, const SDL_Rect& src, const SDL_Rect& dest) {
    SDL_RenderCopy(renderer, texture_, &src, &dest);
}

Texture::~Texture() {
    if(texture_) {
        SDL_DestroyTexture(texture_);
    }
}
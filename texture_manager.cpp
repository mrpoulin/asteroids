#include "texture_manager.hpp"
#include <SDL_image.h>

Texture::Ptr TextureManager::loadTexture(SDL_Renderer* renderer, const std::string path) {

    auto it = textureCache_.find(path);
    if (it != textureCache_.end()) {
        return it->second;
    }

    SDL_Surface* surface = IMG_Load(path.c_str());

    if(!surface) {
        return nullptr;
    }

    SDL_Texture* sdlTex = SDL_CreateTextureFromSurface(renderer, surface); 

    if(!sdlTex) {
        return nullptr;
    }

    SDL_FreeSurface(surface);

    Texture::Ptr managedTex = std::make_shared<Texture>(Texture(sdlTex));

    textureCache_[path] = managedTex;

    return managedTex;
}
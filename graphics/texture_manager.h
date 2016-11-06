#ifndef __TEXTURE_MANAGER_HPP__
#define __TEXTURE_MANAGER_HPP__

#include <memory>
#include <string>
#include <SDL.h>
#include <unordered_map>
#include "texture.h"

class TextureManager {
    private:
        std::unordered_map<std::string, Texture::Ptr> textureCache_;
    public:
        TextureManager() = default;
        TextureManager(const TextureManager&) = delete;
        TextureManager& operator=(const TextureManager&) = delete;

        Texture::Ptr loadTexture(SDL_Renderer*, const std::string);
        SDL_Texture* leLoad(SDL_Renderer* renderer, const std::string path);
};

#endif
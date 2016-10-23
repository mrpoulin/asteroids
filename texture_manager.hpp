#ifndef __TEXTURE_MANAGER_HPP__
#define __TEXTURE_MANAGER_HPP__

#include <memory>
#include <string>
#include <SDL.h>
#include <unordered_map>
#include "texture.hpp"

class TextureManager {
    private:
        std::unordered_map<std::string, Texture::Ptr> textureCache_;
    public:
        TextureManager(const TextureManager&) = delete;
        TextureManager& operator=(const TextureManager&) = delete;

        Texture::Ptr loadTexture(SDL_Renderer*, const std::string);
};

#endif
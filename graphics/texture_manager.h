/////////////////////////////////////////////////////////////////////////////////////////
// Loads and manages textures.
// Textures are loaded from files and cached to prevent re-loading.
/////////////////////////////////////////////////////////////////////////////////////////

#ifndef GRAPHICS_TEXTURE_MANAGER_H
#define GRAPHICS_TEXTURE_MANAGER_H

#include <memory>
#include <string>
#include <SDL.h>
#include <unordered_map>
#include "texture.h"

namespace asteroids {
namespace graphics {

class TextureManager {
public:
    TextureManager() = default;
    TextureManager(const TextureManager&) = delete;
    TextureManager& operator=(const TextureManager&) = delete;

    Texture::Ptr loadTexture(SDL_Renderer*, const std::string);
private:
    std::unordered_map<std::string, Texture::Ptr> textureCache_;
};

} // graphics
} // asteroids

#endif // GRAPHICS_TEXTURE_MANAGER_HPP__

#include "sprite_component.h"

namespace asteroids {
namespace component {

bool SpriteComponent::handle(message::SetSpriteSequenceMessage& msg) {
    if(spriteSequences_.find(msg.newKey) == spriteSequences_.end()) {
        return false;
    }

    currentKey_ = msg.newKey;
    currentFrame_ = spriteSequences_[currentKey_].begin();
    return true;
}

} // component
} // asteroids

/////////////////////////////////////////////////////////////////////////////////////////
// Contains information about the sprite used to draw an entity.
// Only one texture may be linked to a sprite. To accomodate animation, each sprite
// component contains map of keys to sequences of clipping coordinates. Each render,
// the next set of clipping coordinates is used to render the sprite, looping back to the
// beginning of the list if necessary.
//
// { SequenceKey: [Frame1, Frame2, ...], SequenceKey2: [...] }
//                ----------vvv--------
//                     FrameSequence
//
// The list of rendered sprites can be changed via a message on an entity.
/////////////////////////////////////////////////////////////////////////////////////////

#ifndef COMPONENT_SPRITE_COMPONENT_H
#define COMPONENT_SPRITE_COMPONENT_H

#include <map>
#include <string>
#include <list>
#include "component.h"
#include "common/game_types.h"
#include "graphics/renderable.h"
#include "messages/message.h"

namespace asteroids {
namespace component {

class SpriteComponent : public Component,
    public message::MessageHandler<message::SetSpriteSequenceMessage> 
{
public:
    struct Frame {
        common::ScreenPosition x, y;
        common::ScreenDimension width, height;
        
        Frame() = default;
        Frame(common::ScreenPosition x, common::ScreenPosition y,
              common::ScreenPosition width, common::ScreenPosition height): x{x}, y{y}, width{width}, height{height} {}
    };

    typedef std::list<Frame> FrameSequence;
    typedef std::string SequenceKey;

    // Points to the underlying object that will be rendered.
    graphics::Renderable::Ptr renderable;

    SpriteComponent(graphics::Renderable::Ptr renderable): renderable{renderable}, currentKey_{""} {}

    void addFrameTo(SequenceKey sequence, const Frame& frame) {
        spriteSequences_[sequence].push_back(frame);

        // Initialize currentKey_ & currentFrame_ together if this is the first frame added.
        if (currentKey_.empty()) {
            currentKey_ = sequence;
            currentFrame_ = spriteSequences_[sequence].begin();
        }
    }

    bool getCurrentFrame(Frame& frame) {
        if(spriteSequences_[currentKey_].size() <= 0) {
            return false;
        }

        // Shortcut for 1 frame sequences.
        if(spriteSequences_[currentKey_].size() == 1) {
            frame = *currentFrame_;
            return true;
        }

        // Loop currentFrame_ iterator back to beginning.
        if(currentFrame_ == spriteSequences_[currentKey_].end())
            currentFrame_ = spriteSequences_[currentKey_].begin();
        
        frame = *currentFrame_;
        currentFrame_++;

        return true;
    }

    bool handle(message::SetSpriteSequenceMessage& msg);
private:

    std::map<SequenceKey, FrameSequence> spriteSequences_;
    // Represents the current sprite sequence we take frames from.
    SequenceKey currentKey_;
    // Represents the current frame to render in the sprite sequence.
    FrameSequence::iterator currentFrame_;
};

} // component
} // asteroids

#endif // COMPONENT_SPRITE_COMPONENT_H

/////////////////////////////////////////////////////////////////////////////////////////
// This system updates the physics of an object. This includes position, speed, 
// acceleration, etc.
/////////////////////////////////////////////////////////////////////////////////////////

#ifndef SYSTEM_PHYSICS_SYSTEM_H
#define SYSTEM_PHYSICS_SYSTEM_H

#include "system.h"
#include "messages/message.h"
#include "entity/entity_manager.h"
#include "messages/state.h"

namespace asteroids {
namespace system {

class PhysicsSystem: public System,
                     public message::MessageHandler<message::AccelerateState>,
                     public message::MessageHandler<message::RotateState> {
public:

    PhysicsSystem(entity::EntityManager::Ptr e): entityManager_(e) {}
    
    virtual void update(double delta) override;

    bool handle(message::AccelerateState& s) override;
    bool handle(message::RotateState& s) override;
private:
    entity::EntityManager::Ptr entityManager_;
};

} // system
} // asteroids

#endif // SYSTEM_PHYSICS_SYSTEM_H

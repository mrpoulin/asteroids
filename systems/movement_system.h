#ifndef __MOVEMENT_SYSTEM_H__
#define __MOVEMENT_SYSTEM_H__

#include "system.h"
#include "entity_manager.h"
#include "action.h"

class MovementSystem: public System {
public:
    MovementSystem(EntityManager::Ptr e): entityManager_(e) {}

    virtual void update(double delta) override;
private:
    EntityManager::Ptr entityManager_;
};

#endif
#ifndef __PHYSICS_SYSTEM_H__
#define __PHYSICS_SYSTEM_H__

#include "system.h"
#include "entity/entity_manager.h"
#include "input/action.h"

class PhysicsSystem: public System,
                     public MessageHandler<AccelerateState>,
                     public MessageHandler<RotateState> {
public:
    static constexpr double PI = 3.1415926535897932384626433832;
    static constexpr double DEGREE_TO_RAD = PI/180;

    PhysicsSystem(EntityManager::Ptr e): entityManager_(e) {}
    
    virtual void update(double delta) override;

    bool handle(AccelerateState& s) override;
    bool handle(RotateState& s) override;
private:
    EntityManager::Ptr entityManager_;
};

#endif
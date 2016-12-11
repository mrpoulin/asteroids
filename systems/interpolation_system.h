#ifndef __INTERPOLATION_SYSTEM_H__
#define __INTERPOLATION_SYSTEM_H__

#include "system.h"
#include "entity/entity_manager.h"

class InterpolationSystem: public System {
public:
    InterpolationSystem(EntityManager::Ptr e): entityManager_(e) {}

    virtual void update(double delta) override;
private:
    EntityManager::Ptr entityManager_;
};


#endif
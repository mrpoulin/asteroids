#ifndef SYSTEM_RENDERING_SYSTEM_H_
#define SYSTEM_RENDERING_SYSTEM_H_

#include <memory>
#include "system.hpp"
#include "entity_manager.hpp"

class RenderingSystem : public SystemInterface {
  public:
    RenderingSystem(std::shared_ptr<EntityManager> em);

    virtual void update(double delta) override;
  private:
    std::shared_ptr<EntityManager> entity_manager_;
}

#endif
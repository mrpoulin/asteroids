#ifndef __SYSTEM_HPP__
#define __SYSTEM_HPP__

#include "entity_manager.hpp"

class System : public MessageHandlerBase {
	private:
		std::shared_ptr<EntityManager> entityManager_;
	public:
		System(std::shared_ptr<EntityManager> em): entityManager_{em} {}
		virtual void update() = 0;
		virtual ~System() {};
};

#endif

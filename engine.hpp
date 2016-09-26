#ifndef __ENGINE_HPP__
#define __ENGINE_HPP__

#include "system.hpp"

class Engine {
	private:
		std::shared_ptr<EntityManager> entityManager_;
		std::vector<System> systems_;
	public:
		Engine(const Engine&) = delete;
		Engine& operator=(const Engine&) = delete;

		void gameLoop();
};

#endif

#ifndef __TEST_SYSTEM_HPP__
#define __TEST_SYSTEM_HPP__

#include "system.hpp"
#include <iostream>

class TestSystem : public System,
				   public MessageHandler<NullAction>
{
	public:
		TestSystem(std::shared_ptr<EntityManager> em): System{em} {}
		void update() override {}

		bool handle(NullAction& a) override {
			std::cout << "got a null action!@!@" << std::endl;
			return true;
		}
};

#endif
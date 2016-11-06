#ifndef __TEST_SYSTEM_HPP__
#define __TEST_SYSTEM_HPP__

#include "system.h"
#include <iostream>

class TestSystem : public System,
				   public MessageHandler<NullAction>
{
	public:
		void update(double delta) override {}

		bool handle(NullAction& a) override {
			std::cout << "got a null action!@!@" << std::endl;
			return true;
		}
};

#endif
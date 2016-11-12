#ifndef __SYSTEM_HPP__
#define __SYSTEM_HPP__

#include <memory>
#include "message.h"

class System : public MessageHandlerBase {
	public:
		virtual void update(double delta) = 0;
		virtual ~System() {};

		typedef std::shared_ptr<System> Ptr;
};

#endif

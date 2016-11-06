#ifndef __SYSTEM_HPP__
#define __SYSTEM_HPP__

#include "message.h"

class System : public MessageHandlerBase {
	public:
		virtual void update(double delta) = 0;
		virtual ~System() {};
};

#endif

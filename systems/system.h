#ifndef SYSTEM_SYSTEM_H
#define SYSTEM_SYSTEM_H

#include <memory>
#include "messages/message.h"

namespace asteroids {
namespace system {

class System : public message::MessageHandlerBase {
	public:
		virtual void update(double delta) = 0;
		virtual ~System() {}

		typedef std::shared_ptr<System> Ptr;
};

} // system
} // asteroids

#endif // SYSTEM_SYSTEM_H

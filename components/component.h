/////////////////////////////////////////////////////////////////////////////////////////
// Defines a component in entity-component-system system.
// A component acts as a container for data that systems can manipulate. Components
// can also receive messages.
/////////////////////////////////////////////////////////////////////////////////////////

#ifndef COMPONENTS_COMPONENT_H
#define COMPONENTS_COMPONENT_H

#include <typeindex>
#include <memory>
#include "messages/message.h"

namespace asteroids {
namespace component {

class Component : public message::MessageHandlerBase {

public:
	// TODO: Remove?
	virtual ~Component() {}
	typedef std::shared_ptr<Component> Ptr;
};

// A component is keyed as it's type index.
typedef std::type_index ComponentId;

template <typename T>
ComponentId getComponentId() {
	return std::type_index(typeid(T));
}

ComponentId getComponentId(const Component&);


} // component
} // asteroids

#endif // COMPONENTS_COMPONENT_H

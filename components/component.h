#ifndef __COMPONENT_HPP__
#define __COMPONENT_HPP__

#include "message.h"
#include <typeindex>
#include <memory>

typedef std::type_index ComponentId;

class Component : public MessageHandlerBase {
public:
	virtual ~Component() {}

	typedef std::shared_ptr<Component> Ptr;
};

template <typename T>
ComponentId getComponentId() {
	return std::type_index(typeid(T));
}

ComponentId getComponentId(const Component&);

#endif

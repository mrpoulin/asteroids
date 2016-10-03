#ifndef __COMPONENT_HPP__
#define __COMPONENT_HPP__

#include "message.hpp"
#include <typeindex>
#include <memory>

typedef std::type_index ComponentId;

class Component : public MessageHandlerBase {
};

template <typename T>
ComponentId getComponentId() {
	return std::type_index(typeid(T));
}

ComponentId getComponentId(const Component&);

#endif

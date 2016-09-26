#ifndef __COMPONENT_HPP__
#define __COMPONENT_HPP__

#include <typeindex>
#include <memory>

typedef std::type_index ComponentId;

class Component {};

template <typename T>
ComponentId getComponentId() {
	return std::type_index(typeid(T));
}

ComponentId getComponentId(std::shared_ptr<Component> c) {
	return std::type_index(typeid(*c));
}

#endif

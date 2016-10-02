#ifndef __COMPONENT_HPP__
#define __COMPONENT_HPP__

#include "message.hpp"
#include <typeindex>
#include <memory>

typedef std::type_index ComponentId;

class Component {
	public:
		virtual bool receive(std::shared_ptr<Message>) = 0;
};

template <typename T>
ComponentId getComponentId() {
	return std::type_index(typeid(T));
}

ComponentId getComponentId(const std::shared_ptr<const Component>);

#endif

#include "component.hpp"

ComponentId getComponentId(const std::shared_ptr<const Component> c) {
	// Workaround for clang
	const Component& cr = *c;
	return std::type_index(typeid(cr));
}

#include "component.h"

ComponentId getComponentId(const Component &c) {
	return std::type_index(typeid(c));
}

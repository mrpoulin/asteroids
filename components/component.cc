#include "component.h"

namespace asteroids {
namespace component {

ComponentId getComponentId(const Component &c) {
	return std::type_index(typeid(c));
}

} // component
} // asteroids

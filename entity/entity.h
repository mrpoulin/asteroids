/////////////////////////////////////////////////////////////////////////////////////////
// The entity manager stores every entity in the game and it's associated components.
// An entity is simply an integer that is akin to a primary key in a database. Each
// associated component represents a column. Fetching an entity gives us the row
// corresponding to that primary key, with the data for each associated component.
// Each system then reads/writes that data as necessary.
/////////////////////////////////////////////////////////////////////////////////////////

#ifndef ENTITY_ENTITY_H
#define ENTITY_ENTITY_H

namespace asteroids {
namespace entity {

typedef unsigned long long Entity;

} // entity
} // asteroids

#endif // ENTITY_ENTITY_H

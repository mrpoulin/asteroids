/////////////////////////////////////////////////////////////////////////////////////////
// Shared game types. 
/////////////////////////////////////////////////////////////////////////////////////////

#ifndef COMMON_GAME_TYPES_H
#define COMMON_GAME_TYPES_H

namespace asteroids {
namespace common {
// Using int because SDL does.
typedef int ScreenPosition;
typedef int ScreenDimension;

typedef float LogicalPosition;
typedef float LogicalDimension;

} // common
} // asteroids


#endif // COMMON_GAME_TYPES_H
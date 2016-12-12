/////////////////////////////////////////////////////////////////////////////////////////
// Represents the rotation of an object in 2D space.
/////////////////////////////////////////////////////////////////////////////////////////

#ifndef COMMON_ROTATION_2D_H
#define COMMON_ROTATION_2D_H

#include <cmath>
#include "vec2d.h"
#include "game_constants.h"

namespace asteroids {
namespace common {

// Global constant.
constexpr double DEGREE_TO_RAD = PI / 180;

template <typename T>
class Rotation2D {
public:

    Rotation2D(): radians_{0}, expireCachedVec_{true} {}
    Rotation2D(T r): radians_{r}, expireCachedVec_{true} {}

    inline T asDegrees() const { return radians_ * static_cast<T>(DEGREE_TO_RAD); }
    inline T asRadians() const { return radians_; }

    inline Rotation2D& operator+=(const Rotation2D& o) {
        radians_ = modAngle(radians_ + o.radians);
		return *this;
	}

    // Scalar addition
    inline Rotation2D& operator+=(const T& t) {
        expireCachedVec_ = true;
        radians_ = modAngle(radians_ + t);
		return *this;
	}

    inline Rotation2D& operator-=(const Rotation2D& o) {
        expireCachedVec_ = true;
        radians_ = modAngle(radians_ - o.radians);
		return *this;
	}

    // Scalar subtraction
    inline Rotation2D& operator-=(const T& t) {
        expireCachedVec_ = true;
        radians_ = modAngle(radians_ - t);
		return *this;
	}

    inline Rotation2D operator-() const {
        return {-radians_};
    }

    inline friend bool operator==(const Rotation2D& lhs, const Rotation2D& rhs) {
		return lhs.radians_ == rhs.radians_;
	}

    inline friend bool operator!=(const Rotation2D& lhs, const Rotation2D& rhs) {
		return !(lhs == rhs);
	}

    operator Vec2D<T>() const {
        if(expireCachedVec_) {
            cachedVec_ = {std::cos(radians_), std::sin(radians_)};
            expireCachedVec_ = false;
        }
        
        return cachedVec_;
    }

private:

    T radians_;
    mutable bool expireCachedVec_;
    mutable Vec2D<T> cachedVec_;

    T modAngle(T rads) {
        T twopi = static_cast<T>(TWO_PI);
        return rads - twopi * floor(rads / twopi);
    }
};

template <typename T>
inline Rotation2D<T> operator+(const Rotation2D<T>& lhs, const Rotation2D<T>& rhs) {
	return Rotation2D<T>(lhs) += rhs;
}

// Scalar addition
template <typename T>
inline Rotation2D<T> operator+(const Rotation2D<T>& lhs, const T& rhs) {
	return Rotation2D<T>(lhs) += rhs;
}

template <typename T>
inline Rotation2D<T> operator-(const Rotation2D<T>& lhs, const Rotation2D<T>& rhs) {
	return Rotation2D<T>(lhs) -= rhs;
}

// Scalar subtraction
template <typename T>
inline Rotation2D<T> operator-(const Rotation2D<T>& lhs, const T& rhs) {
	return Rotation2D<T>(lhs) -= rhs;
}

template <typename T>
T degreeToRad(const T& degrees) {
    return degrees * static_cast<T>(DEGREE_TO_RAD);
}


} // common
} // asteroids


#endif // COMMON_ROTATION_2D_H

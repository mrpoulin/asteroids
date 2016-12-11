/////////////////////////////////////////////////////////////////////////////////////////
// Represents the rotation of an object in 2D space.
/////////////////////////////////////////////////////////////////////////////////////////

#ifndef COMMON_ROTATION_2D_H
#define COMMON_ROTATION_2D_H

#include "vec2d.h"
#include <cmath>

namespace asteroids {
namespace common {

template <typename T>
class Rotation2D {
public:

    Rotation2D(): radians_{0}, expireCachedVec_{true} {};
    Rotation2D(T r): radians_{r}, expireCachedVec_{true} {}

    inline T asDegrees() const { return radians_ * (T)DEGREE_TO_RAD; }
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

    inline friend bool operator==(const Rotation2D& lhs, const Rotation2D& rhs) const {
		return lhs.radians_ == rhs.radians_;
	}

    inline friend bool operator!=(const Rotation2D& lhs, const Rotation2D& rhs) const {
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

    static constexpr double PI = 3.14159265359;
    static constexpr double DEGREE_TO_RAD = PI / (double)180;
    static constexpr double TWO_PI = 2 * PI;

    T radians_;
    mutable bool expireCachedVec_;
    mutable Vec2D<T> cachedVec_;

    T modAngle(T rads) {
        return rads - (T)TWO_PI * floor(rads / (T)TWO_PI); 
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


} // common
} // asteroids


#endif // COMMON_ROTATION_2D_H
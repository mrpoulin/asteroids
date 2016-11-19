#ifndef __VEC2D__H__
#define __VEC2D__H__

#include <stdexcept>
#include <cmath>
#include <tuple>

template <typename T>
class Vec2D {
	public:

	T x, y;
	
	Vec2D(): x{0}, y{0} {}
	Vec2D(const T& x, const T& y): x{x}, y{y} {}

	inline T& operator[](int idx) const {
		if (idx == 0)
			return x;
		else if (idx == 1)
			return y;
		else
			throw std::out_of_range("Vec2D index must be 0 or 1.");
	}

	inline Vec2D operator/=(const T& t) {
		x /= t;
		y /= t;
		return *this;
	}
	
	inline Vec2D operator*=(const T& t)  {
		x *= t;
		y *= t;
		return *this;
	}

	Vec2D& operator+=(const Vec2D& o) {
		x += o.x;
		y += o.y;
		return *this;
	}
	
	Vec2D& operator-=(const Vec2D& o) {
		x -= o.x;
		y -= o.y;
		return *this;
	}

	Vec2D operator -() {
		return {-x, -y};
	}
	

	inline friend bool operator==(const Vec2D& lhs, const Vec2D& rhs) {
		return std::tie(lhs.x, lhs.y) == std::tie(rhs.x, rhs.y);
	}

	inline friend bool operator!=(const Vec2D& lhs, const Vec2D& rhs) {
		return !(lhs == rhs);
	}
};

template <typename T>
inline Vec2D<T> operator+(const Vec2D<T>& lhs, const Vec2D<T>& rhs) {
	return Vec2D<T>(lhs) += rhs;
}

template <typename T>
inline Vec2D<T> operator-(const Vec2D<T>& lhs, const Vec2D<T>& rhs) {
	return Vec2D<T>(lhs) -= rhs;
}

template <typename T>
inline Vec2D<T> operator*(const Vec2D<T>& v, const T& t) {
	return Vec2D<T>(v) *= t;
}

template <typename T>
inline Vec2D<T> operator*(const T& t, const Vec2D<T>& v) {
	return Vec2D<T>(v) *= t;
}

template <typename T>
inline Vec2D<T> operator/(const Vec2D<T>& v, const T& t) {
	return Vec2D<T>(v) /= t;
}

template <typename T>
inline Vec2D<T> operator/(const T& t, const Vec2D<T>& v) {
	return Vec2D<T>(v) /= t;
}

template <typename T>
inline T euclideanNorm(const Vec2D<T>& v) {
	return std::sqrt(v.x * v.x + v.y * v.y);
}

template <typename T>
inline T dot(const Vec2D<T>& v1, const Vec2D<T>& v2) {
	return v1.x * v2.x +  v1.y * v2.y;
}

template <typename T>
inline T rotation(const Vec2D<T>& v) {
	return std::atan(v.y / v.x);
}

#endif

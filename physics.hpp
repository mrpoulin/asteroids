#ifndef __PHYSICS_HPP__
#define __PHYSICS_HPP__

#include "vec2d.hpp"
#include <cmath>

template <typename T>
class Physics {
	private:
		Vec2D<T> position_;
		Vec2D<T> velocity_;
		Vec2D<T> acceleration_;
	public:
		Physics(const Vec2D<T>& position);

		static constexpr double PI = 3.1415926535897932384626433832;
		static constexpr double DEGREE_TO_RAD = PI/180;

		void move() {
			position_.x += velocity_.x;
			position_.y += velocity_.y;
		}

		void rotate(T degrees, const Vec2D<T>& origin) {
			T rad = degrees * Physics::DEGREE_TO_RAD;

			T cd = std::cos(degrees);
			T sd = std::sin(degrees);

			T translated_x = velocity_.x - origin.x;
			T translated_y = velocity_.y - origin.y;

			velocity_.x  = (translated_x * cd - translated_y * sd) + origin.x;
			velocity_.y  = (translated_x * sd + translated_y * cd) + origin.y;
		}
};



#endif

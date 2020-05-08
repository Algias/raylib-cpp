#ifndef RAYLIB_CPP_VECTOR2_HPP_
#define RAYLIB_CPP_VECTOR2_HPP_
namespace raylib {
#ifdef __cplusplus
	extern "C" {
#endif
#include "raylib.h"
#ifndef RAYLIB_CPP_NO_MATH
#include "raymath.h"
#endif
#ifdef __cplusplus
	}
#endif
}
#include "./raylib-cpp-utils.hpp"

#ifndef RAYLIB_CPP_NO_MATH
#include <cmath>

namespace raylibcpp {

#endif
	class Vector2 : public raylib::Vector2 {
	public:
		Vector2(raylib::Vector2 vec) {
			set(vec);
		};
		Vector2(float X = 0, float Y = 0) {
			x = X;
			y = Y;
		};
		inline void set(raylib::Vector2 vec) {
			x = vec.x;
			y = vec.y;
		}

		GETTERSETTER(float, X, x)
			GETTERSETTER(float, Y, y)

			Vector2& operator=(const raylib::Vector2& vector2) {
			set(vector2);
			return *this;
		}

		Vector2& operator=(const Vector2& vector2) {
			set(vector2);
			return *this;
		}

		bool operator==(const Vector2& other) {
			return x == other.x
				&& y == other.y;
		}

#ifndef RAYLIB_CPP_NO_MATH
		Vector2 Add(const Vector2& vector2) {
			return Vector2Add(*this, vector2);
		}

		Vector2 operator+(const Vector2& vector2) {
			return Vector2Add(*this, vector2);
		}

		Vector2 Subtract(const Vector2& vector2) {
			return Vector2Subtract(*this, vector2);
		}

		Vector2 operator-(const Vector2& vector2) {
			return Vector2Subtract(*this, vector2);
		}

		Vector2 Negate() {
			return Vector2Negate(*this);
		}

		Vector2 operator-() {
			return Vector2Negate(*this);
		}

		Vector2 Multiply(const Vector2& vector2) {
			return Vector2MultiplyV(*this, vector2);
		}

		Vector2 operator*(const Vector2& vector2) {
			return Vector2MultiplyV(*this, vector2);
		}

		Vector2 Scale(const float scale) {
			return Vector2Scale(*this, scale);
		}

		Vector2 operator*(const float scale) {
			return Vector2Scale(*this, scale);
		}

		Vector2 Divide(const Vector2& vector2) {
			return Vector2DivideV(*this, vector2);
		}

		Vector2 operator/(const Vector2& vector2) {
			return Vector2DivideV(*this, vector2);
		}

		Vector2 Divide(const float div) {
			return Vector2Divide(*this, div);
		}

		Vector2 operator/(const float div) {
			return Vector2Divide(*this, div);
		}

		Vector2& operator+=(const Vector2& vector2) {
			set(Vector2Add(*this, vector2));

			return *this;
		}

		Vector2& operator-=(const Vector2& vector2) {
			set(Vector2Subtract(*this, vector2));

			return *this;
		}


		Vector2& operator*=(const Vector2& vector2) {
			set(Vector2MultiplyV(*this, vector2));

			return *this;
		}

		Vector2& operator*=(const float scale) {
			set(Vector2Scale(*this, scale));

			return *this;
		}

		Vector2& operator/=(const Vector2& vector2) {
			set(Vector2DivideV(*this, vector2));

			return *this;
		}

		Vector2& operator/=(const float div) {
			set(Vector2Divide(*this, div));

			return *this;
		}

		float Length() {
			return Vector2Length(*this);
		}

		Vector2 Normalize() {
			return Vector2Normalize(*this);
		}

		float DotProduct(const Vector2& vector2) {
			return Vector2DotProduct(*this, vector2);
		}

		float Angle(const Vector2& vector2) {
			return Vector2Angle(*this, vector2);
		}

		float Distance(const Vector2& vector2) {
			return Vector2Distance(*this, vector2);
		}

		Vector2 Lerp(const Vector2& vector2, const float amount) {
			return Vector2Lerp(*this, vector2, amount);
		}

		Vector2 Rotate(float degrees) {
			return Vector2Rotate(*this, degrees);
		}

		static Vector2 Zero() {
			return raylib::Vector2Zero();
		}

		static Vector2 One() {
			return raylib::Vector2One();
		}
#endif

		inline Vector2& DrawPixel(raylib::Color color) {
			raylib::DrawPixelV(*this, color);
			return *this;
		}

		inline Vector2& DrawLine(raylib::Vector2 endPos, raylib::Color color) {
			raylib::DrawLineV(*this, endPos, color);
			return *this;
		}

		inline Vector2& DrawLine(raylib::Vector2 endPos, float thick, raylib::Color color) {
			raylib::DrawLineEx(*this, endPos, thick, color);
			return *this;
		}

		inline Vector2& DrawLineBezier(raylib::Vector2 endPos, float thick, raylib::Color color) {
			raylib::DrawLineBezier(*this, endPos, thick, color);
			return *this;
		}

		inline Vector2& DrawCircle(float radius, raylib::Color color) {
			raylib::DrawCircleV(*this, radius, color);
			return *this;
		}

		inline Vector2& DrawRectangle(raylib::Vector2 size, raylib::Color color) {
			raylib::DrawRectangleV(*this, size, color);
			return *this;
		}

		inline Vector2& DrawPoly(int sides, float radius, float rotation, raylib::Color color) {
			raylib::DrawPoly(*this, sides, radius, rotation, color);
			return *this;
		}
	};
}

#endif

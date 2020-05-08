#ifndef RAYLIB_CPP_VECTOR4_HPP_
#define RAYLIB_CPP_VECTOR4_HPP_

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
#endif

#include <Vector3.hpp>
#include <utility>

namespace raylibcpp {

	class Vector4 : public raylib::Vector4 {
	public:
		Vector4(raylib::Vector4 vec) {
			set(vec);
		};

		Vector4(float X = 0, float Y = 0, float Z = 0, float W = 0) {
			x = X;
			y = Y;
			z = Z;
			w = W;
		};

		Vector4(raylib::Color color) {
			set(ColorNormalize(color));
		}

		inline void set(raylib::Vector4 vec4) {
			x = vec4.x;
			y = vec4.y;
			z = vec4.z;
			w = vec4.w;
		}

		GETTERSETTER(float, X, x)
			GETTERSETTER(float, Y, y)
			GETTERSETTER(float, Z, z)
			GETTERSETTER(float, W, w)

			Vector4& operator=(const raylib::Vector4& vector4) {
			set(vector4);
			return *this;
		}

		raylib::Vector4& operator=(const Vector4& vector4) {
			set(vector4);
			return *this;
		}

		bool operator==(const Vector4& other) {
			return x == other.x
				&& y == other.y
				&& z == other.z
				&& w == other.w;
		}

#ifndef RAYLIB_CPP_NO_MATH
		Vector4 Multiply(const Vector4& vector4) {
			return QuaternionMultiply(*this, vector4);
		}

		Vector4 operator*(const Vector4& vector4) {
			return QuaternionMultiply(*this, vector4);
		}

		Vector4 Lerp(const Vector4& vector4, float amount) {
			return QuaternionLerp(*this, vector4, amount);
		}

		Vector4 Nlerp(const Vector4& vector4, float amount) {
			return QuaternionNlerp(*this, vector4, amount);
		}

		Vector4 Slerp(const Vector4& vector4, float amount) {
			return QuaternionSlerp(*this, vector4, amount);
		}

		Matrix ToMatrix() {
			return QuaternionToMatrix(*this);
		}

		float Length() {
			return QuaternionLength(*this);
		}

		Vector4 Normalize() {
			return QuaternionNormalize(*this);
		}

		Vector4 Invert() {
			return QuaternionInvert(*this);
		}

		void ToAxisAngle(Vector3* outAxis, float* outAngle) {
			return QuaternionToAxisAngle(*this, outAxis, outAngle);
		}

		std::pair<Vector3, float> ToAxisAngle() {
			Vector3 outAxis;
			float outAngle;

			QuaternionToAxisAngle(*this, &outAxis, &outAngle);

			std::pair<Vector3, float> out(outAxis, outAngle);

			return out;
		}

		Vector4 Transform(const raylib::Matrix& matrix) {
			return raylib::QuaternionTransform(*this, matrix);
		}

		static Vector4 Identity() {
			return raylib::QuaternionIdentity();
		}

		static Vector4 FromVector3ToVector3(const Vector3& from, const Vector3& to) {
			return raylib::QuaternionFromVector3ToVector3(from, to);
		}

		static Vector4 FromMatrix(const raylib::Matrix& matrix) {
			return raylib::QuaternionFromMatrix(matrix);
		}

		static Vector4 FromAxisAngle(const Vector3& axis, const float angle) {
			return raylib::QuaternionFromAxisAngle(axis, angle);
		}

		static Vector4 FromEuler(const float roll, const float pitch, const float yaw) {
			return raylib::QuaternionFromEuler(roll, pitch, yaw);
		}

		static Vector4 FromEuler(const Vector3& vector3) {
			return raylib::QuaternionFromEuler(vector3.x, vector3.y, vector3.z);
		}

		Vector3 ToEuler() {
			return raylib::QuaternionToEuler(*this);
		}
#endif

		raylib::Color ColorFromNormalized() {
			return raylib::ColorFromNormalized(*this);
		}
	};

	// Alias the Vector4 as Quaternion.
	typedef Vector4 Quaternion;
}

#endif

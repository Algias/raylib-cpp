#ifndef RAYLIB_CPP_MATRIX_HPP_
#define RAYLIB_CPP_MATRIX_HPP_



#include "./raylib-cpp-utils.hpp"
#ifndef RAYLIB_CPP_NO_MATH
#include <cmath>
#endif
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

#include <Vector3.hpp>

namespace raylibcpp {

	class Matrix : public raylib::Matrix {
	public:
		Matrix(raylib::Matrix mat) {
			set(mat);
		};

		Matrix(float M0 = 0, float M1 = 0, float M2 = 0, float M3 = 0, float M4 = 0, float M5 = 0, float M6 = 0, float M7 = 0, float M8 = 0, float M9 = 0, float M10 = 0, float M11 = 0, float M12 = 0, float M13 = 0, float M14 = 0, float M15 = 0) {
			m0 = M0;
			m1 = M1;
			m2 = M2;
			m3 = M3;
			m4 = M4;
			m5 = M5;
			m6 = M6;
			m7 = M7;
			m8 = M8;
			m9 = M9;
			m10 = M10;
			m11 = M11;
			m12 = M12;
			m13 = M13;
			m14 = M14;
			m15 = M15;
		};

		inline void set(raylib::Matrix mat) {
			m0 = mat.m0;
			m1 = mat.m1;
			m2 = mat.m2;
			m3 = mat.m3;
			m4 = mat.m4;
			m5 = mat.m5;
			m6 = mat.m6;
			m7 = mat.m7;
			m8 = mat.m8;
			m9 = mat.m9;
			m10 = mat.m10;
			m11 = mat.m11;
			m12 = mat.m12;
			m13 = mat.m13;
			m14 = mat.m14;
			m15 = mat.m15;
		}

		GETTERSETTER(float, M0, m0)
			GETTERSETTER(float, M1, m1)
			GETTERSETTER(float, M2, m2)
			GETTERSETTER(float, M3, m3)
			GETTERSETTER(float, M4, m4)
			GETTERSETTER(float, M5, m5)
			GETTERSETTER(float, M6, m6)
			GETTERSETTER(float, M7, m7)
			GETTERSETTER(float, M8, m8)
			GETTERSETTER(float, M9, m9)
			GETTERSETTER(float, M10, m10)
			GETTERSETTER(float, M11, m11)
			GETTERSETTER(float, M12, m12)
			GETTERSETTER(float, M13, m13)
			GETTERSETTER(float, M14, m14)
			GETTERSETTER(float, M15, m15)

			Matrix& operator=(const raylib::Matrix& matrix) {
			set(matrix);
			return *this;
		}

		raylib::Matrix& operator=(const Matrix& matrix) {
			set(matrix);
			return *this;
		}

		bool operator==(const Matrix& other) {
			return m0 == other.m0
				&& m1 == other.m1
				&& m2 == other.m2
				&& m3 == other.m3
				&& m4 == other.m4
				&& m5 == other.m5
				&& m6 == other.m6
				&& m7 == other.m7
				&& m8 == other.m8
				&& m9 == other.m9
				&& m10 == other.m10
				&& m11 == other.m11
				&& m12 == other.m12
				&& m13 == other.m13
				&& m14 == other.m14
				&& m15 == other.m15;
		}

		inline Matrix& SetProjection() {
			raylib::SetMatrixProjection(*this);
			return *this;
		}

		inline Matrix& SetModelview() {
			raylib::SetMatrixModelview(*this);
			return *this;
		}

		static Matrix GetModelview() {
			return raylib::GetMatrixModelview();
		}

		static Matrix GetProjection() {
			return raylib::GetMatrixProjection();
		}

#ifndef RAYLIB_CPP_NO_MATH
		float Trace() {
			return raylib::MatrixTrace(*this);
		}
		Matrix Transpose() {
			return raylib::MatrixTranspose(*this);
		}
		Matrix Invert() {
			return raylib::MatrixInvert(*this);
		}
		Matrix Normalize() {
			return raylib::MatrixNormalize(*this);
		}
		static Matrix Identity() {
			return raylib::MatrixIdentity();
		}
		Matrix Add(raylib::Matrix right) {
			return raylib::MatrixAdd(*this, right);
		}
		Matrix operator+(const Matrix& matrix) {
			return raylib::MatrixAdd(*this, matrix);
		}
		Matrix Subtract(raylib::Matrix right) {
			return raylib::MatrixSubtract(*this, right);
		}
		Matrix operator-(const Matrix& matrix) {
			return raylib::MatrixSubtract(*this, matrix);
		}
		static Matrix Translate(float x, float y, float z) {
			return raylib::MatrixTranslate(x, y, z);
		}
		static Matrix Rotate(Vector3 axis, float angle) {
			return raylib::MatrixRotate(axis, angle);
		}
		static Matrix RotateXYZ(Vector3 angle) {
			return raylib::MatrixRotateXYZ(angle);
		}
		static Matrix RotateX(float angle) {
			return raylib::MatrixRotateX(angle);
		}
		static Matrix RotateY(float angle) {
			return raylib::MatrixRotateY(angle);
		}
		static Matrix RotateZ(float angle) {
			return raylib::MatrixRotateZ(angle);
		}
		static Matrix Scale(float x, float y, float z) {
			return raylib::MatrixScale(x, y, z);
		}
		Matrix Multiply(Matrix right) {
			return raylib::MatrixMultiply(*this, right);
		}
		Matrix operator*(const Matrix& matrix) {
			return raylib::MatrixMultiply(*this, matrix);
		}

		static Matrix Frustum(double left, double right, double bottom, double top, double near, double far) {
			return raylib::MatrixFrustum(left, right, bottom, top, near, far);
		}

		static Matrix Perspective(double fovy, double aspect, double near, double far) {
			return raylib::MatrixPerspective(fovy, aspect, near, far);
		}

		static Matrix Ortho(double left, double right, double bottom, double top, double near, double far) {
			return raylib::MatrixOrtho(left, right, bottom, top, near, far);
		}

		static Matrix LookAt(Vector3 eye, Vector3 target, Vector3 up) {
			return raylib::MatrixLookAt(eye, target, up);
		}

		raylib::float16 ToFloatV() {
			return raylib::MatrixToFloatV(*this);
		}
		operator raylib::float16() {
			return ToFloatV();
		}
#endif
	};
}


#endif

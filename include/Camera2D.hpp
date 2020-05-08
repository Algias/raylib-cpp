#ifndef RAYLIB_CPP_CAMERA_HPP_
#define RAYLIB_CPP_CAMERA_HPP_



#include "./Vector2.hpp"
#include "./raylib-cpp-utils.hpp"

namespace raylib {
#ifdef __cplusplus
	extern "C" {
#endif
#include "raylib.h"
#ifdef __cplusplus
	}
#endif
}

namespace raylibcpp {

	class Camera2D : public raylib::Camera2D {
	public:
		Camera2D(raylib::Vector2 offsetValue, raylib::Vector2 targetValue, float rotationValue = 0, float zoomValue = 1) {
			offset = offsetValue;
			target = targetValue;
			rotation = rotationValue;
			zoom = zoomValue;
		};

		inline void set(const raylib::Camera2D& camera) {
			offset = camera.offset;
			target = camera.target;
			rotation = camera.rotation;
			zoom = camera.zoom;
		}

		inline void set(const Camera2D& camera) {
			offset = camera.offset;
			target = camera.target;
			rotation = camera.rotation;
			zoom = camera.zoom;
		}

		inline Camera2D& BeginMode2D() {
			raylib::BeginMode2D(*this);
			return *this;
		}
		inline Camera2D& EndMode2D() {
			raylib::EndMode2D();
			return *this;
		}

		GETTERSETTER(Vector2, Offset, offset)
			GETTERSETTER(Vector2, Target, target)
			GETTERSETTER(float, Rotation, rotation)
			GETTERSETTER(float, Zoom, zoom)

			Camera2D& operator=(const raylib::Camera2D& camera) {
			set(camera);
			return *this;
		}

		raylib::Camera2D& operator=(const Camera2D& camera) {
			set(camera);
			return *this;
		}

		inline raylib::Matrix GetMatrix() {
			return raylib::GetCameraMatrix2D(*this);
		}
		inline Vector2 GetWorldToScreen2D(Vector2 position) {
			return raylib::GetWorldToScreen2D(position, *this);
		}
		inline Vector2 GetScreenToWorld2D(Vector2 position) {
			return raylib::GetScreenToWorld2D(position, *this);
		}
	};
}

#endif

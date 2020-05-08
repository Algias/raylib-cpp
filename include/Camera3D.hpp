#ifndef RAYLIB_CPP_CAMERA3D_HPP_
#define RAYLIB_CPP_CAMERA3D_HPP_



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

#include <Matrix.hpp>
#include <Ray.hpp>
#include <Vector3.hpp>
#include <Texture2D.hpp>
namespace raylibcpp {

	class Camera3D : public raylib::Camera3D {
	public:
		Camera3D(raylib::Vector3 positionValue, raylib::Vector3 targetValue, raylib::Vector3 upValue, float fovyValue = 0, int typeValue = 0) {
			position = positionValue;
			target = targetValue;
			up = upValue;
			fovy = fovyValue;
			type = typeValue;
		};

		Camera3D() {}

		GETTERSETTER(Vector3, Position, position)
			GETTERSETTER(Vector3, Target, target)
			GETTERSETTER(Vector3, Up, up)
			GETTERSETTER(float, Fovy, fovy)
			GETTERSETTER(int, Type, type)

			Camera3D& operator=(const raylib::Camera3D& camera) {
			set(camera);
			return *this;
		}

		raylib::Camera3D& operator=(const Camera3D& camera) {
			set(camera);
			return *this;
		}

		inline void set(const raylib::Camera3D& camera) {
			position = camera.position;
			target = camera.target;
			up = camera.up;
			fovy = camera.fovy;
			type = camera.type;
		}

		inline void set(const Camera3D& camera) {
			position = camera.position;
			target = camera.target;
			up = camera.up;
			fovy = camera.fovy;
			type = camera.type;
		}

		Camera3D& BeginMode3D() {
			raylib::BeginMode3D(*this);
			return *this;
		}
		Camera3D& EndMode3D() {
			raylib::EndMode3D();
			return *this;
		}

		inline Matrix GetMatrix() {
			return raylib::GetCameraMatrix(*this);
		}

		inline Camera3D& SetMode(int mode) {
			raylib::SetCameraMode(*this, mode);
			return *this;
		}

		inline Camera3D& SetAltControl(int altKey) {
			raylib::SetCameraAltControl(altKey);
			return *this;
		}

		inline Camera3D& SetSmoothZoomControl(int szKey) {
			raylib::SetCameraSmoothZoomControl(szKey);
			return *this;
		}

		inline Camera3D& SetMoveControls(int frontKey, int backKey, int rightKey, int leftKey, int upKey, int downKey) {
			raylib::SetCameraMoveControls(frontKey, backKey, rightKey, leftKey, upKey, downKey);
			return *this;
		}

		inline Camera3D& Update() {
			raylib::UpdateCamera(this);
			return *this;
		}

		inline Camera3D& UpdateVrTracking() {
			raylib::UpdateVrTracking(this);
			return *this;
		}

		inline Ray GetMouseRay(raylib::Vector2 mousePosition) {
			return raylib::GetMouseRay(mousePosition, *this);
		}

		inline Vector2 GetWorldToScreen(raylib::Vector3 position) {
			return raylib::GetWorldToScreen(position, *this);
		}

		inline Camera3D& DrawBillboard(raylib::Texture2D texture, raylib::Vector3 center, float size, raylib::Color tint = WHITE) {
			raylib::DrawBillboard(*this, texture, center, size, tint);
			return *this;
		}

		inline Camera3D& DrawBillboard(Texture2D texture, Rectangle sourceRec, Vector3 center, float size, raylib::Color tint = WHITE) {
			raylib::DrawBillboardRec(*this, texture, sourceRec, center, size, tint);
			return *this;
		}
	};

	typedef Camera3D Camera;
}

#endif

#ifndef RAYLIB_CPP_RAY_HPP_
#define RAYLIB_CPP_RAY_HPP_



#include "./raylib-cpp-utils.hpp"

#include "./RayHitInfo.hpp"

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

	class Ray : public raylib::Ray {
	public:
		Ray(raylib::Ray ray) {
			set(ray);
		};

		Ray(raylib::Vector3 Position, raylib::Vector3 Direction) {
			position = Position;
			direction = Direction;
		};

		Ray(raylib::Vector2 mousePosition, raylib::Camera camera) {
			set(GetMouseRay(mousePosition, camera));
		}

		inline void set(raylib::Ray ray) {
			position = ray.position;
			direction = ray.direction;
		}

		Ray& operator=(const raylib::Ray& ray) {
			set(ray);
			return *this;
		}

		raylib::Ray& operator=(const Ray& ray) {
			set(ray);
			return *this;
		}

		GETTERSETTER(raylib::Vector3, Position, position)
			GETTERSETTER(raylib::Vector3, Direction, direction)

			inline Ray& Draw(raylib::Color color) {
			DrawRay(*this, color);
			return *this;
		}

		inline bool CheckCollisionSphere(raylib::Vector3 center, float radius) {
			return CheckCollisionRaySphere(*this, center, radius);
		}

		inline bool CheckCollisionSphereEx(raylib::Vector3 center, float radius, raylib::Vector3* collisionPoint) {
			return CheckCollisionRaySphereEx(*this, center, radius, collisionPoint);
		}

		inline bool CheckCollisionBox(raylib::BoundingBox box) {
			return CheckCollisionRayBox(*this, box);
		}

		inline RayHitInfo GetCollisionModel(raylib::Model model) {
			return GetCollisionRayModel(*this, model);
		}

		inline RayHitInfo GetCollisionTriangle(raylib::Vector3 p1, raylib::Vector3 p2, raylib::Vector3 p3) {
			return GetCollisionRayTriangle(*this, p1, p2, p3);
		}

		inline RayHitInfo GetCollisionGround(float groundHeight) {
			return GetCollisionRayGround(*this, groundHeight);
		}
	};
}

#endif

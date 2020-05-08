#ifndef RAYLIB_CPP_BOUNDINGBOX_HPP_
#define RAYLIB_CPP_BOUNDINGBOX_HPP_

namespace raylib {
#ifdef __cplusplus
	extern "C" {
#endif
#include "raylib.h"
#ifdef __cplusplus
	}
#endif
}

#include "./raylib-cpp-utils.hpp"

namespace raylibcpp {

	class BoundingBox : public raylib::BoundingBox {
	public:
		BoundingBox(raylib::BoundingBox box) {
			set(box);
		};
		BoundingBox(raylib::Mesh mesh) {
			set(MeshBoundingBox(mesh));
		}
		BoundingBox(raylib::Vector3 Min, raylib::Vector3 Max) {
			min = Min;
			max = Max;
		};
		inline void set(raylib::BoundingBox box) {
			min = box.min;
			max = box.max;
		}

		GETTERSETTER(raylib::Vector3, Min, min)
			GETTERSETTER(raylib::Vector3, Max, max)

			BoundingBox& operator=(const raylib::BoundingBox& box) {
			set(box);
			return *this;
		}

		BoundingBox& operator=(const BoundingBox& box) {
			set(box);
			return *this;
		}

		inline BoundingBox& Draw(raylib::Color color = raylib::WHITE) {
			DrawBoundingBox(*this, color);
			return *this;
		}

		inline bool CheckCollision(raylib::BoundingBox box2) {
			return CheckCollisionBoxes(*this, box2);
		}

		inline bool CheckCollision(raylib::Vector3 center, float radius) {
			return CheckCollisionBoxSphere(*this, center, radius);
		}

		inline bool CheckCollision(raylib::Ray ray) {
			return CheckCollisionRayBox(ray, *this);
		}
	};
}

#endif

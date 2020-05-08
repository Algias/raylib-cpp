#ifndef RAYLIB_CPP_RAYHITINFO_HPP_
#define RAYLIB_CPP_RAYHITINFO_HPP_


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


	class RayHitInfo : public raylib::RayHitInfo {
	public:
		RayHitInfo(raylib::RayHitInfo ray) {
			set(ray);
		};

		RayHitInfo(bool Hit, float Distance, raylib::Vector3 Position, raylib::Vector3 Normal) {
			hit = Hit;
			distance = Distance;
			position = Position;
			normal = Normal;
		};

		RayHitInfo& operator=(const raylib::RayHitInfo& ray) {
			set(ray);
			return *this;
		}

		RayHitInfo& operator=(const RayHitInfo& ray) {
			set(ray);
			return *this;
		}

		inline void set(raylib::RayHitInfo ray) {
			hit = ray.hit;
			distance = ray.distance;
			position = ray.position;
			normal = ray.normal;
		}

		GETTERSETTER(bool, Hit, hit)
			GETTERSETTER(float, Distance, distance)
			GETTERSETTER(raylib::Vector3, Position, position)
			GETTERSETTER(raylib::Vector3, Normal, normal)
	};
}

#endif

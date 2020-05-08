#ifndef RAYLIB_CPP_MATERIAL_HPP_
#define RAYLIB_CPP_MATERIAL_HPP_


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


	class Material : public raylib::Material {
	public:
		Material(raylib::Material material) {
			set(material);
		};

		Material() {
			set(raylib::LoadMaterialDefault());
		};

		~Material() {
			Unload();
		}

		inline void set(raylib::Material material) {
			shader = material.shader;
			maps = material.maps;
			params = material.params;
		}

		GETTERSETTER(raylib::Shader, Shader, shader)

			Material& operator=(const raylib::Material& material) {
			set(material);
			return *this;
		}

		Material& operator=(const Material& material) {
			set(material);
			return *this;
		}

		inline void Unload() {
			raylib::UnloadMaterial(*this);
		}

		inline Material& SetTexture(int mapType, raylib::Texture2D texture) {
			raylib::SetMaterialTexture(this, mapType, texture);
			return *this;
		}

	};
}

#endif

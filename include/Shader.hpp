#ifndef RAYLIB_CPP_SHADER_HPP_
#define RAYLIB_CPP_SHADER_HPP_



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

	class Shader : public raylib::Shader {
	public:
		Shader(raylib::Shader shader) {
			set(shader);
		};

		Shader(unsigned int Id, int* Locs) {
			id = Id;
			locs = Locs;
		};

		Shader() {
			set(raylib::GetShaderDefault());
		}

		inline void set(raylib::Shader shader) {
			id = shader.id;
			locs = shader.locs;
		}

		GETTERSETTER(unsigned int, Id, id)
			GETTERSETTER(int*, Locs, locs)

			Shader& operator=(const raylib::Shader& shader) {
			set(shader);
			return *this;
		}

		raylib::Shader& operator=(const Shader& shader) {
			set(shader);
			return *this;
		}

		~Shader() {
			Unload();
		}

		void Unload() {
			raylib::UnloadShader(*this);
		}

		static Shader Load(const std::string& vsFileName, const std::string& fsFileName) {
			return raylib::LoadShader(vsFileName.c_str(), fsFileName.c_str());
		}
		static Shader LoadCode(const std::string& vsCode, const std::string& fsCode) {
			char* param1 = (char*)vsCode.c_str();
			char* param2 = (char*)fsCode.c_str();
			return raylib::LoadShaderCode(param1, param2);
		}

		inline Shader& BeginShaderMode() {
			raylib::BeginShaderMode(*this);
			return *this;
		}

		inline Shader& EndShaderMode() {
			raylib::EndShaderMode();
			return *this;
		}

		inline int GetLocation(const std::string& uniformName) {
			return raylib::GetShaderLocation(*this, uniformName.c_str());
		}
	};
}

#endif

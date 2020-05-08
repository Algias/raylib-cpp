#ifndef RAYLIB_CPP_RENDERTEXTURE2D_HPP_
#define RAYLIB_CPP_RENDERTEXTURE2D_HPP_



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

	class RenderTexture2D : public raylib::RenderTexture2D {
	public:
		RenderTexture2D(raylib::RenderTexture2D renderTexture) {
			set(renderTexture);
		};
		RenderTexture2D(unsigned int Id) {
			id = Id;
		};
		RenderTexture2D(int width, int height) {
			set(raylib::LoadRenderTexture(width, height));
		}

		inline void set(raylib::RenderTexture2D renderTexture) {
			id = renderTexture.id;
			texture = renderTexture.texture;
			depth = renderTexture.depth;
			depthTexture = renderTexture.depthTexture;
		}

		GETTERSETTER(unsigned int, Id, id)
			GETTERSETTER(raylib::Texture2D, Texture, texture)
			GETTERSETTER(raylib::Texture2D, Depth, depth)
			GETTERSETTER(bool, DepthTexture, depthTexture)

			RenderTexture2D& operator=(const raylib::RenderTexture2D& texture) {
			set(texture);
			return *this;
		}

		RenderTexture2D& operator=(const RenderTexture2D& texture) {
			set(texture);
			return *this;
		}

		~RenderTexture2D() {
			Unload();
		};

		inline void Unload() {
			UnloadRenderTexture(*this);
		}

		inline RenderTexture2D& BeginTextureMode() {
			raylib::BeginTextureMode(*this);
			return *this;
		}

		inline RenderTexture2D& EndTextureMode() {
			raylib::EndTextureMode();
			return *this;
		}
	};
	typedef RenderTexture2D RenderTexture;
}

#endif

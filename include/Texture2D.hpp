#ifndef RAYLIB_CPP_TEXTURE2D_HPP_
#define RAYLIB_CPP_TEXTURE2D_HPP_

#include <string>

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
#include "./Vector2.hpp"
#include "./Material.hpp"
#include <Image.hpp>

namespace raylibcpp {

	class Texture2D : public raylib::Texture2D {
	public:
		Texture2D() {
			set(raylib::GetTextureDefault());
		};

		Texture2D(raylib::Image& image) {
			LoadFromImage(image);
		}

		Texture2D(const std::string& fileName) {
			Load(fileName);
		}

		~Texture2D() {
			Unload();
		};

		inline void set(raylib::Texture2D texture) {
			id = texture.id;
			width = texture.width;
			height = texture.height;
			mipmaps = texture.mipmaps;
			format = texture.format;
		}

		GETTERSETTER(unsigned int, Id, id)
			GETTERSETTER(int, Width, width)
			GETTERSETTER(int, Height, height)
			GETTERSETTER(int, Mipmaps, mipmaps)
			GETTERSETTER(int, Format, format)

			Texture2D& operator=(const raylib::Texture2D& texture) {
			set(texture);
			return *this;
		}

		raylib::Texture2D& operator=(const Texture2D& texture) {
			set(texture);
			return *this;
		}

		void LoadFromImage(raylib::Image& image) {
			set(raylib::LoadTextureFromImage(image));
		}

		void LoadTextureCubemap(raylib::Image& image, int layoutType) {
			set(raylib::LoadTextureCubemap(image, layoutType));
		}

		void Load(const std::string& fileName) {
			set(raylib::LoadTexture(fileName.c_str()));
		}

		inline void Unload() {
			raylib::UnloadTexture(*this);
		}

		inline Texture2D& Update(const void* pixels) {
			raylib::UpdateTexture(*this, pixels);
			return *this;
		}

		inline Image GetTextureData() {
			return raylib::GetTextureData(*this);
		}
		inline operator raylib::Image() {
			return GetTextureData();
		}

		inline Texture2D& GenMipmaps() {
			raylib::GenTextureMipmaps(this);
			return *this;
		}

		inline Texture2D& SetFilter(int filterMode) {
			raylib::SetTextureFilter(*this, filterMode);
			return *this;
		}

		inline Texture2D& SetWrap(int wrapMode) {
			raylib::SetTextureWrap(*this, wrapMode);
			return *this;
		}

		inline Texture2D& Draw(int posX, int posY, raylib::Color tint = WHITE) {
			raylib::DrawTexture(*this, posX, posY, tint);
			return *this;
		}

		inline Texture2D& Draw(raylib::Vector2 position, raylib::Color tint = WHITE) {
			raylib::DrawTextureV(*this, position, tint);
			return *this;
		}
		inline Texture2D& Draw(raylib::Vector2 position, float rotation, float scale = 1.0f, raylib::Color tint = WHITE) {
			raylib::DrawTextureEx(*this, position, rotation, scale, tint);
			return *this;
		}

		inline Texture2D& Draw(raylib::Rectangle sourceRec, raylib::Vector2 position, raylib::Color tint = WHITE) {
			raylib::DrawTextureRec(*this, sourceRec, position, tint);
			return *this;
		}
		inline Texture2D& Draw(raylib::Vector2 tiling, raylib::Vector2 offset, raylib::Rectangle quad, raylib::Color tint = WHITE) {
			raylib::DrawTextureQuad(*this, tiling, offset, quad, tint);
			return *this;
		}
		inline Texture2D& Draw(raylib::Rectangle sourceRec, raylib::Rectangle destRec, raylib::Vector2 origin, float rotation = 0, raylib::Color tint = WHITE) {
			raylib::DrawTexturePro(*this, sourceRec, destRec, origin, rotation, tint);
			return *this;
		}
		inline Texture2D& Draw(raylib::NPatchInfo nPatchInfo, raylib::Rectangle destRec, raylib::Vector2 origin, float rotation = 0, raylib::Color tint = WHITE) {
			raylib::DrawTextureNPatch(*this, nPatchInfo, destRec, origin, rotation, tint);
			return *this;
		}

		inline Texture2D& Draw(raylib::Vector3 position, float width, float height, float length, raylib::Color color = WHITE) {
			raylib::DrawCubeTexture(*this, position, width, height, length, color);
			return *this;
		}

		inline Texture2D& SetMaterialTexture(Material* material, int mapType) {
			raylib::SetMaterialTexture(material, mapType, *this);
			return *this;
		}

		static int GetPixelDataSize(int width, int height, int format) {
			return raylib::GetPixelDataSize(width, height, format);
		}
	};

	// Alias the Texture2D as Texture.
	typedef Texture2D Texture;
}

#endif

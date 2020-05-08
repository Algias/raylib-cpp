#ifndef RAYLIB_CPP_FONT_HPP_
#define RAYLIB_CPP_FONT_HPP_

#include <string>



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

	class Font : public raylib::Font {
	public:
		Font() {
			set(raylib::GetFontDefault());
		}

		Font(const std::string& fileName) {
			set(raylib::LoadFont(fileName.c_str()));
		}

		Font(const std::string& fileName, int fontSize, int* fontChars, int charCount) {
			set(raylib::LoadFontEx(fileName.c_str(), fontSize, fontChars, charCount));
		}

		Font(raylib::Image& image, raylib::Color key, int firstChar) {
			set(LoadFontFromImage(image, key, firstChar));
		}

		~Font() {
			Unload();
		}

		void Unload() {
			UnloadFont(*this);
		}

		void set(const raylib::Font font) {
			baseSize = font.baseSize;
			charsCount = font.charsCount;
			texture = font.texture;
			recs = font.recs;
			chars = font.chars;
		}

		void set(const Font& font) {
			baseSize = font.baseSize;
			charsCount = font.charsCount;
			texture = font.texture;
			recs = font.recs;
			chars = font.chars;
		}

		GETTERSETTER(int, BaseSize, baseSize)
			GETTERSETTER(int, CharsCount, charsCount)
			GETTERSETTER(raylib::Texture2D, Texture, texture)
			GETTERSETTER(raylib::Rectangle*, Recs, recs)
			GETTERSETTER(raylib::CharInfo*, Chars, chars)

			Font& operator=(const raylib::Font& font) {
			set(font);
			return *this;
		}

		raylib::Font& operator=(const Font& font) {
			set(font);
			return *this;
		}

		inline Font& DrawText(const std::string& text, raylib::Vector2 position, float fontSize, float spacing, raylib::Color tint = WHITE) {
			raylib::DrawTextEx(*this, text.c_str(), position, fontSize, spacing, tint);
			return *this;
		}
		inline Font& DrawText(const std::string& text, raylib::Rectangle rec, float fontSize, float spacing, bool wordWrap, raylib::Color tint = WHITE) {
			raylib::DrawTextRec(*this, text.c_str(), rec, fontSize, spacing, wordWrap, tint);
			return *this;
		}
		inline Font& DrawText(const std::string& text, raylib::Rectangle rec, float fontSize, float spacing, bool wordWrap, Color tint, int selectStart, int selectLength, raylib::Color selectText, Color selectBack) {
			raylib::DrawTextRecEx(*this, text.c_str(), rec, fontSize, spacing, wordWrap, tint, selectStart, selectLength, selectText, selectBack);
			return *this;
		}

		inline Vector2 MeasureText(const std::string& text, float fontSize, float spacing) {
			return raylib::MeasureTextEx(*this, text.c_str(), fontSize, spacing);
		}

		inline int GetGlyphIndex(int character) {
			return raylib::GetGlyphIndex(*this, character);
		}
	};
}

#endif

#ifndef RAYLIB_CPP_COLOR_HPP_
#define RAYLIB_CPP_COLOR_HPP_

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

#include <Rectangle.hpp>
namespace raylibcpp {

	class Color : public raylib::Color {
	public:
		Color() {
			r = 0;
			g = 0;
			b = 0;
			a = 255;
		}
		Color(raylib::Color color) {
			r = color.r;
			g = color.g;
			b = color.b;
			a = color.a;
		}
		Color(unsigned char red, unsigned char green, unsigned char blue, unsigned char alpha = 255) {
			r = red;
			g = green;
			b = blue;
			a = alpha;
		};
		Color(raylib::Vector3 hsv) {
			set(raylib::ColorFromHSV(hsv));
		};
		Color(int hexValue) {
			set(raylib::GetColor(hexValue));
		};
		Color(raylib::Vector4 normalized) {
			set(raylib::ColorFromNormalized(normalized));
		}

		inline void set(const raylib::Color& color) {
			r = color.r;
			g = color.g;
			b = color.b;
			a = color.a;
		}

		inline void set(const Color& color) {
			r = color.r;
			g = color.g;
			b = color.b;
			a = color.a;
		}

		static Color LightGray;
		static Color Gray;
		static Color DarkGray;
		static Color Yellow;
		static Color Gold;
		static Color Orange;
		static Color Pink;
		static Color Red;
		static Color Maroon;
		static Color Green;
		static Color Lime;
		static Color DarkGreen;
		static Color SkyBlue;
		static Color Blue;
		static Color DarkBlue;
		static Color Purple;
		static Color Violet;
		static Color DarkPurple;
		static Color Beige;
		static Color Brown;
		static Color DarkBrown;
		static Color White;
		static Color Black;
		static Color Blank;
		static Color Magenta;
		static Color RayWhite;

		int ToInt() {
			return raylib::ColorToInt(*this);
		}

		operator int() const { return raylib::ColorToInt(*this); }

		Color Fade(float alpha) {
			Color _a;
			_a.set(raylib::Fade(*this, alpha));
			return _a;
		}

		raylib::Vector4 Normalize() {
			return raylib::ColorNormalize(*this);
		}

		raylib::Vector3 ToHSV() {
			return raylib::ColorToHSV(*this);
		}

		GETTERSETTER(unsigned char, R, r)
			GETTERSETTER(unsigned char, G, g)
			GETTERSETTER(unsigned char, B, b)
			GETTERSETTER(unsigned char, A, a)

			Color& operator=(const raylib::Color& color) {
			set(color);
			return *this;
		}

		Color& operator=(const Color& color) {
			set(color);
			return *this;
		}

		inline Color& ClearBackground() {
			raylib::ClearBackground(*this);
			return *this;
		}

		inline Color& DrawPixel(int x, int y) {
			raylib::DrawPixel(x, y, *this);
			return *this;
		}

		inline Color& DrawPixel(raylib::Vector2 pos) {
			raylib::DrawPixelV(pos, *this);
			return *this;
		}

		inline Color& DrawLine(int startPosX, int startPosY, int endPosX, int endPosY) {
			raylib::DrawLine(startPosX, startPosY, endPosX, endPosY, *this);
			return *this;
		}
		inline Color& DrawLine(raylib::Vector2 startPos, raylib::Vector2 endPos) {
			raylib::DrawLineV(startPos, endPos, *this);
			return *this;
		}
		inline Color& DrawLine(raylib::Vector2 startPos, raylib::Vector2 endPos, float thick) {
			raylib::DrawLineEx(startPos, endPos, thick, *this);
			return *this;
		}
		inline Color& DrawLineBezier(raylib::Vector2 startPos, Vector2 endPos, float thick) {
			raylib::DrawLineBezier(startPos, endPos, thick, *this);
			return *this;
		}
		inline Color& DrawLineStrip(raylib::Vector2* points, int numPoints) {
			raylib::DrawLineStrip(points, numPoints, *this);
			return *this;
		}

		inline Color& DrawText(const std::string& text, int posX, int posY, int fontSize) {
			raylib::DrawText(text.c_str(), posX, posY, fontSize, *this);
			return *this;
		}
		inline Color& DrawText(raylib::Font font, const std::string& text, raylib::Vector2 position, float fontSize, float spacing) {
			raylib::DrawTextEx(font, text.c_str(), position, fontSize, spacing, *this);
			return *this;
		}

		inline Color& DrawText(raylib::Font font, const std::string& text, raylib::Rectangle rec, float fontSize, float spacing, bool wordWrap = false) {
			raylib::DrawTextRec(font, text.c_str(), rec, fontSize, spacing, wordWrap, *this);
			return *this;
		}

		inline Color& DrawRectangle(int posX, int posY, int width, int height) {
			raylib::DrawRectangle(posX, posY, width, height, *this);
			return *this;
		}

		inline Color& DrawRectangle(Vector2 position, Vector2 size) {
			raylib::DrawRectangleV(position, size, *this);
			return *this;
		}

		inline Color& DrawRectangle(Rectangle rec) {
			raylib::DrawRectangleRec(rec, *this);
			return *this;
		}

		inline Color& DrawRectangle(Rectangle rec, Vector2 origin, float rotation) {
			raylib::DrawRectanglePro(rec, origin, rotation, *this);
			return *this;
		}

		inline Color& DrawRectangleLines(int posX, int posY, int width, int height) {
			raylib::DrawRectangleLines(posX, posY, width, height, *this);
			return *this;
		}

		inline Color& DrawRectangleLines(Rectangle rec, int lineThick) {
			raylib::DrawRectangleLinesEx(rec, lineThick, *this);
			return *this;
		}

	};

	inline Color Color::LightGray = raylib::LIGHTGRAY;
	inline Color Color::Gray = raylib::GRAY;
	inline Color Color::DarkGray = raylib::DARKGRAY;
	inline Color Color::Yellow = raylib::YELLOW;
	inline Color Color::Gold = raylib::GOLD;
	inline Color Color::Orange = raylib::ORANGE;
	inline Color Color::Pink = raylib::PINK;
	inline Color Color::Red = raylib::RED;
	inline Color Color::Maroon = raylib::MAROON;
	inline Color Color::Green = raylib::GREEN;
	inline Color Color::Lime = raylib::LIME;
	inline Color Color::DarkGreen = raylib::DARKGREEN;
	inline Color Color::SkyBlue = raylib::SKYBLUE;
	inline Color Color::Blue = raylib::BLUE;
	inline Color Color::DarkBlue = raylib::DARKBLUE;
	inline Color Color::Purple = raylib::PURPLE;
	inline Color Color::Violet = raylib::VIOLET;
	inline Color Color::DarkPurple = raylib::DARKPURPLE;
	inline Color Color::Beige = raylib::BEIGE;
	inline Color Color::Brown = raylib::BROWN;
	inline Color Color::DarkBrown = raylib::DARKBROWN;
	inline Color Color::White = raylib::WHITE;
	inline Color Color::Black = raylib::BLACK;
	inline Color Color::Blank = raylib::BLANK;
	inline Color Color::Magenta = raylib::MAGENTA;
	inline Color Color::RayWhite = raylib::RAYWHITE;
}
#endif

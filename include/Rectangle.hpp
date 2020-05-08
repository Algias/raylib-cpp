#ifndef RAYLIB_CPP_RECTANGLE_HPP_
#define RAYLIB_CPP_RECTANGLE_HPP_

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

namespace raylibcpp {

	class Rectangle : public raylib::Rectangle {
	public:
		Rectangle(raylib::Rectangle vec) {
			set(vec);
		};
		Rectangle(float X = 0, float Y = 0, float Width = 0, float Height = 0) {
			x = X;
			y = Y;
			width = Width;
			height = Height;
		};

		inline void set(raylib::Rectangle rect) {
			x = rect.x;
			y = rect.y;
			width = rect.width;
			height = rect.height;
		}

		GETTERSETTER(float, X, x)
			GETTERSETTER(float, Y, y)
			GETTERSETTER(float, Width, width)
			GETTERSETTER(float, Height, height)

			Rectangle& operator=(const raylib::Rectangle& rect) {
			set(rect);
			return *this;
		}

		raylib::Rectangle& operator=(const Rectangle& rect) {
			set(rect);
			return *this;
		}

		inline Rectangle& Draw(raylib::Color color) {
			raylib::DrawRectangle(static_cast<int>(x), static_cast<int>(y), static_cast<int>(width), static_cast<int>(height), color);
			return *this;
		}
		inline Rectangle& Draw(raylib::Vector2 origin, float rotation, raylib::Color color) {
			raylib::DrawRectanglePro(*this, origin, rotation, color);
			return *this;
		}

		inline Rectangle& DrawGradientV(raylib::Color color1, raylib::Color color2) {
			raylib::DrawRectangleGradientH(static_cast<int>(x), static_cast<int>(y), static_cast<int>(width), static_cast<int>(height), color1, color2);
			return *this;
		}
		inline Rectangle& DrawGradientH(raylib::Color color1, raylib::Color color2) {
			raylib::DrawRectangleGradientH(static_cast<int>(x), static_cast<int>(y), static_cast<int>(width), static_cast<int>(height), color1, color2);
			return *this;
		}
		inline Rectangle& DrawGradient(raylib::Color col1, raylib::Color col2, raylib::Color col3, raylib::Color col4) {
			raylib::DrawRectangleGradientEx(*this, col1, col2, col3, col4);
			return *this;
		}
		inline Rectangle& DrawLines(raylib::Color color) {
			raylib::DrawRectangleLines(static_cast<int>(x), static_cast<int>(y), static_cast<int>(width), static_cast<int>(height), color);
			return *this;
		}
		inline Rectangle& DrawLinesEx(int lineThick, raylib::Color color) {
			raylib::DrawRectangleLinesEx(*this, lineThick, color);
			return *this;
		}
		inline Rectangle& DrawRounded(float roundness, int segments, raylib::Color color) {
			raylib::DrawRectangleRounded(*this, roundness, segments, color);
			return *this;
		}
		inline Rectangle& DrawRoundedLines(float roundness, int segments, int lineThick, raylib::Color color) {
			raylib::DrawRectangleRoundedLines(*this, roundness, segments, lineThick, color);
			return *this;
		}

		inline bool CheckCollision(raylib::Rectangle rec2) {
			return raylib::CheckCollisionRecs(*this, rec2);
		}
		inline Rectangle GetCollision(raylib::Rectangle rec2) {
			return raylib::GetCollisionRec(*this, rec2);
		}
		inline bool CheckCollision(raylib::Vector2 point) {
			return raylib::CheckCollisionPointRec(point, *this);
		}
	};
}

#endif

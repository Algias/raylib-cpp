#ifndef RAYLIB_CPP_MOUSE_HPP_
#define RAYLIB_CPP_MOUSE_HPP_



#include "./Vector2.hpp"
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

	class Mouse {
	public:
		inline bool IsButtonPressed(int button) {
			return raylib::IsMouseButtonPressed(button);
		}
		inline bool IsButtonDown(int button) {
			return raylib::IsMouseButtonDown(button);
		}
		inline bool IsButtonReleased(int button) {
			return raylib::IsMouseButtonReleased(button);
		}
		inline bool IsButtonUp(int button) {
			return raylib::IsMouseButtonUp(button);
		}
		inline int GetX() {
			return raylib::GetMouseX();
		}
		inline int GetY() {
			return raylib::GetMouseY();
		}
		inline Mouse& SetX(int x) {
			raylib::SetMouseOffset(x, GetY());
			return *this;
		}
		inline Mouse& SetY(int y) {
			raylib::SetMouseOffset(GetX(), y);
			return *this;
		}
		inline Vector2 GetPosition() {
			return raylib::GetMousePosition();
		}
		inline Mouse& SetPosition(int x, int y) {
			raylib::SetMousePosition(x, y);
			return *this;
		}
		inline Mouse& SetOffset(int offsetX, int offsetY) {
			raylib::SetMouseOffset(offsetX, offsetY);
			return *this;
		}
		inline Mouse& SetScale(float scaleX, float scaleY) {
			raylib::SetMouseScale(scaleX, scaleY);
			return *this;
		}
		inline int GetWheelMove() {
			return raylib::GetMouseWheelMove();
		}
		inline int GetTouchX() {
			return raylib::GetTouchX();
		}
		inline int GetTouchY() {
			return raylib::GetTouchY();
		}
		inline Vector2 GetTouchPosition(int index) {
			return raylib::GetTouchPosition(index);
		}
	};
}

#endif

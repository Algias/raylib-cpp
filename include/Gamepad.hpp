#ifndef RAYLIB_CPP_GAMEPAD_HPP_
#define RAYLIB_CPP_GAMEPAD_HPP_

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

	class Gamepad {
	public:
		Gamepad(int gamepadNumber = 0) {
			set(gamepadNumber);
		}
		int number;

		inline void set(int gamepadNumber) {
			number = gamepadNumber;
		}

		GETTERSETTER(int, Number, number)

			Gamepad& operator=(const Gamepad& gamepad) {
			set(gamepad);
			return *this;
		}

		operator int() const { return number; }

		inline bool IsAvailable() {
			return raylib::IsGamepadAvailable(number);
		}
		inline bool IsName(const std::string& name) {
			return raylib::IsGamepadName(number, name.c_str());
		}
		std::string GetName() {
			return std::string(raylib::GetGamepadName(number));
		}
		inline bool IsButtonPressed(int button) {
			return raylib::IsGamepadButtonPressed(number, button);
		}

		inline bool IsButtonDown(int button) {
			return raylib::IsGamepadButtonDown(number, button);
		}

		inline bool IsButtonReleased(int button) {
			return raylib::IsGamepadButtonReleased(number, button);
		}
		inline bool IsButtonUp(int button) {
			return raylib::IsGamepadButtonUp(number, button);
		}

		inline int GetButtonPressed() {
			return raylib::GetGamepadButtonPressed();
		}

		inline int GetAxisCount() {
			return raylib::GetGamepadAxisCount(number);
		}

		inline float GetAxisMovement(int axis) {
			return raylib::GetGamepadAxisMovement(number, axis);
		}
	};
}

#endif

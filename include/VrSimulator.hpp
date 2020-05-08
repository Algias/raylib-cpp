#ifndef RAYLIB_CPP_VRSIMULATOR_HPP_
#define RAYLIB_CPP_VRSIMULATOR_HPP_



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

	class VrSimulator {
	public:
		VrSimulator() {
			Init();
		};
		VrSimulator(raylib::VrDeviceInfo info, Shader distortion) {
			Init();
			Set(info, distortion);
		};

		inline void Init() {
			raylib::InitVrSimulator();
		}

		~VrSimulator() {
			Close();
		}

		inline bool IsReady() {
			return raylib::IsVrSimulatorReady();
		}

		inline VrSimulator& Update(Camera* camera) {
			raylib::UpdateVrTracking(camera);
			return *this;
		}
		inline VrSimulator& Set(raylib::VrDeviceInfo info, Shader distortion) {
			raylib::SetVrConfiguration(info, distortion);
			return *this;
		}
		inline VrSimulator& Toggle() {
			raylib::ToggleVrMode();
			return *this;
		}
		inline VrSimulator& Begin() {
			raylib::BeginVrDrawing();
			return *this;
		}
		inline VrSimulator& End() {
			raylib::EndVrDrawing();
			return *this;
		}
		inline void Close() {
			raylib::CloseVrSimulator();
		}
	};
}

#endif

#ifndef RAYLIB_CPP_AUDIODEVICE_HPP_
#define RAYLIB_CPP_AUDIODEVICE_HPP_



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

	/**
	 * Audio device management functions.
	 */
	class AudioDevice {
	public:
		/**
		 * Initialize audio device and context.
		 *
		 * @param lateInit Whether or not to post-pone initializing the context.
		 */
		AudioDevice(bool lateInit = false) {
			if (!lateInit) {
				Init();
			}
		};

		~AudioDevice() {
			Close();
		};

		/**
		 * Initialize audio device and context.
		 */
		inline AudioDevice& Init() {
			raylib::InitAudioDevice();
			return *this;
		}

		/**
		 * Close the audio device and context.
		 */
		inline AudioDevice& Close() {
			raylib::CloseAudioDevice();
			return *this;
		}

		/**
		 * Check if audio device has been initialized successfully.
		 */
		inline bool IsReady() {
			return raylib::IsAudioDeviceReady();
		}

		/**
		 * Set master volume (listener).
		 */
		inline AudioDevice& SetVolume(float volume) {
			raylib::SetMasterVolume(volume);
			return *this;
		}
	};
}

#endif

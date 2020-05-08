#ifndef RAYLIB_CPP_SOUND_HPP_
#define RAYLIB_CPP_SOUND_HPP_

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

	class Sound : public raylib::Sound {
	public:
		Sound(raylib::Sound vec) {
			set(vec);
		};

		Sound(const std::string& fileName) {
			set(raylib::LoadSound(fileName.c_str()));
		};

		Sound(raylib::Wave wave) {
			set(LoadSoundFromWave(wave));
		};

		~Sound() {
			Unload();
		}

		inline void set(raylib::Sound sound) {
			sampleCount = sound.sampleCount;
			stream = sound.stream;
		}

		GETTERSETTER(unsigned int, SampleCount, sampleCount)
			GETTERSETTER(raylib::AudioStream, Stream, stream)

			Sound& operator=(const raylib::Sound& sound) {
			set(sound);
			return *this;
		}

		Sound& operator=(const Sound& sound) {
			set(sound);
			return *this;
		}

		inline Sound& Update(const void* data, int sampleCount) {
			raylib::UpdateSound(*this, data, sampleCount);
			return *this;
		}

		inline void Unload() {
			raylib::UnloadSound(*this);
		}

		inline Sound& Play() {
			raylib::PlaySound(*this);
			return *this;
		}

		inline Sound& Stop() {
			raylib::StopSound(*this);
			return *this;
		}
		inline Sound& Pause() {
			raylib::PauseSound(*this);
			return *this;
		}
		inline Sound& Resume() {
			raylib::ResumeSound(*this);
			return *this;
		}

		inline Sound& PlayMulti() {
			raylib::PlaySoundMulti(*this);
			return *this;
		}

		inline Sound& StopMulti() {
			raylib::StopSoundMulti();
			return *this;
		}

		inline bool IsPlaying() {
			return raylib::IsSoundPlaying(*this);
		}
		inline Sound& SetVolume(float volume) {
			raylib::SetSoundVolume(*this, volume);
			return *this;
		}
		inline Sound& SetPitch(float pitch) {
			raylib::SetSoundPitch(*this, pitch);
			return *this;
		}

	};
}

#endif

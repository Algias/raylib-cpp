#ifndef RAYLIB_CPP_MUSIC_HPP_
#define RAYLIB_CPP_MUSIC_HPP_



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

	class Music : public raylib::Music {
	public:
		Music(raylib::Music music) {
			set(music);
		};

		Music(const std::string& fileName) {
			set(raylib::LoadMusicStream(fileName.c_str()));
		}

		~Music() {
			Unload();
		}

		inline void set(raylib::Music music) {
			ctxType = music.ctxType;
			ctxData = music.ctxData;
			sampleCount = music.sampleCount;
			loopCount = music.loopCount;
			stream = music.stream;
		}

		GETTERSETTER(int, CtxType, ctxType)
			GETTERSETTER(unsigned int, SampleCount, sampleCount)
			GETTERSETTER(unsigned int, LoopCount, loopCount)

			Music& operator=(const raylib::Music& music) {
			set(music);
			return *this;
		}

		raylib::Music& operator=(const Music& music) {
			set(music);
			return *this;
		}

		inline void Unload() {
			raylib::UnloadMusicStream(*this);
		}

		inline Music& Play() {
			raylib::PlayMusicStream(*this);
			return *this;
		}

		inline Music& Update() {
			raylib::UpdateMusicStream(*this);
			return *this;
		}

		inline Music& Stop() {
			raylib::StopMusicStream(*this);
			return *this;
		}

		inline Music& Pause() {
			raylib::PauseMusicStream(*this);
			return *this;
		}
		inline Music& Resume() {
			raylib::ResumeMusicStream(*this);
			return *this;
		}
		inline bool IsPlaying() {
			return raylib::IsMusicPlaying(*this);
		}
		inline Music& SetVolume(float volume) {
			raylib::SetMusicVolume(*this, volume);
			return *this;
		}
		inline Music& SetPitch(float pitch) {
			raylib::SetMusicPitch(*this, pitch);
			return *this;
		}
		inline Music& SetLoopCount(int count) {
			raylib::SetMusicLoopCount(*this, count);
			return *this;
		}
		inline float GetTimeLength() {
			return raylib::GetMusicTimeLength(*this);
		}
		inline float GetTimePlayed() {
			return raylib::GetMusicTimePlayed(*this);
		}


	};
}

#endif

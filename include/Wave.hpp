#ifndef RAYLIB_CPP_WAVE_HPP_
#define RAYLIB_CPP_WAVE_HPP_



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

	class Wave : public raylib::Wave {
	public:
		Wave(raylib::Wave wave) {
			set(wave);
		};

		Wave(unsigned int SampleCount = 0, unsigned int SampleRate = 0, unsigned int SampleSize = 0, unsigned int Channels = 0) {
			sampleCount = SampleCount;
			sampleRate = SampleRate;
			sampleSize = SampleSize;
			channels = Channels;
		};

		Wave(const std::string& fileName) {
			set(raylib::LoadWave(fileName.c_str()));
		}

		~Wave() {
			Unload();
		}

		inline void set(raylib::Wave wave) {
			sampleCount = wave.sampleCount;
			sampleRate = wave.sampleRate;
			sampleSize = wave.sampleSize;
			channels = wave.channels;
			data = wave.data;
		}

		GETTERSETTER(unsigned int, X, sampleCount)
			GETTERSETTER(unsigned int, Y, sampleRate)
			GETTERSETTER(unsigned int, Z, sampleSize)
			GETTERSETTER(unsigned int, W, channels)
			GETTERSETTER(void*, Data, data)

			Wave& operator=(const raylib::Wave& wave) {
			set(wave);
			return *this;
		}

		raylib::Wave& operator=(const Wave& wave) {
			set(wave);
			return *this;
		}

		inline Wave& Format(int SampleRate = 0, int SampleSize = 0, int Channels = 2) {
			raylib::WaveFormat(this, SampleRate, SampleSize, Channels);
			return *this;
		}

		inline Wave Copy() {
			return raylib::WaveCopy(*this);
		}

		inline Wave& Crop(int initSample, int finalSample) {
			raylib::WaveCrop(this, initSample, finalSample);
			return *this;
		}

		inline Wave& Export(const std::string& fileName) {
			raylib::ExportWave(*this, fileName.c_str());
			return *this;
		}
		inline Wave& ExportAsCode(const std::string& fileName) {
			raylib::ExportWaveAsCode(*this, fileName.c_str());
			return *this;
		}

		void Unload() {
			if (data != NULL) {
				raylib::UnloadWave(*this);
				data = NULL;
			}
		}

		inline Sound LoadSound() {
			return raylib::LoadSoundFromWave(*this);
		}

		inline float* GetWaveData() {
			return raylib::GetWaveData(*this);
		}
	};
}

#endif

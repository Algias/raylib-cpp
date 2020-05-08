#ifndef RAYLIB_CPP_AUDIOSTREAM_HPP_
#define RAYLIB_CPP_AUDIOSTREAM_HPP_



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
	 * AudioStream management functions
	 */
	class AudioStream : public raylib::AudioStream {
	public:
		AudioStream(raylib::AudioStream music) {
			set(music);
		};

		/**
		 * Init audio stream (to stream raw audio pcm data)
		 */
		AudioStream(unsigned int SampleRate, unsigned int SampleSize, unsigned int Channels) {
			set(raylib::InitAudioStream(SampleRate, SampleSize, Channels));
		}

		~AudioStream() {
			Close();
		}

		inline void set(raylib::AudioStream stream) {
			sampleRate = stream.sampleRate;
			sampleSize = stream.sampleSize;
			channels = stream.channels;
			buffer = stream.buffer;
		}

		GETTERSETTER(unsigned int, SampleRate, sampleRate)
			GETTERSETTER(unsigned int, SampleSize, sampleSize)
			GETTERSETTER(unsigned int, Channels, channels)

			AudioStream& operator=(const raylib::AudioStream& stream) {
			set(stream);
			return *this;
		}

		AudioStream& operator=(const AudioStream& stream) {
			set(stream);
			return *this;
		}

		/**
		 * Update audio stream buffers with data
		 */
		inline AudioStream& Update(const void* data, int samplesCount) {
			raylib::UpdateAudioStream(*this, data, samplesCount);
			return *this;
		}

		/**
		 * Close audio stream and free memory
		 */
		inline AudioStream& Close() {
			raylib::CloseAudioStream(*this);
			return *this;
		}

		/**
		 * Check if any audio stream buffers requires refill
		 */
		inline bool IsProcessed() {
			return raylib::IsAudioStreamProcessed(*this);
		}

		/**
		 * Play audio stream
		 */
		inline AudioStream& Play() {
			raylib::PlayAudioStream(*this);
			return *this;
		}

		/**
		 * Pause audio stream
		 */
		inline AudioStream& Pause() {
			raylib::PauseAudioStream(*this);
			return *this;
		}

		/**
		 * Resume audio stream
		 */
		inline AudioStream& Resume() {
			raylib::ResumeAudioStream(*this);
			return *this;
		}

		/**
		 * Check if audio stream is playing
		 */
		inline bool IsPlaying() {
			return raylib::IsAudioStreamPlaying(*this);
		}

		/**
		 * Stop audio stream
		 */
		inline AudioStream& Stop() {
			raylib::StopAudioStream(*this);
			return *this;
		}

		/**
		 * Set volume for audio stream (1.0 is max level)
		 */
		inline AudioStream& SetVolume(float volume) {
			raylib::SetAudioStreamVolume(*this, volume);
			return *this;
		}

		/**
		 * Set pitch for audio stream (1.0 is base level)
		 */
		inline AudioStream& SetPitch(float pitch) {
			raylib::SetAudioStreamPitch(*this, pitch);
			return *this;
		}

		/**
		 * Default size for new audio streams
		 */
		inline AudioStream& SetBufferSizeDefault(int size) {
			raylib::SetAudioStreamBufferSizeDefault(size);
			return *this;
		}

	};
}

#endif

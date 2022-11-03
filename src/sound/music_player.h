#pragma once
#include <AL/al.h>
#include <sndfile.h>

#define MP_LOAD wase::sound::MusicPlayer::loadMusic
#define MP_PLAY wase::sound::MusicPlayer::play
#define MP_UPDATE wase::sound::MusicPlayer::updateBufferStream
#define MP_CLEAN wase::sound::MusicPlayer::cleanUp

namespace wase::sound
{
	class MusicPlayer
	{
	public:
		/**
		 * Plays music that was loaded by the loadMusic function
		 * Use this function after the loadMusic function
		*/
		static void play();

		/**
		 *  Loads some music to play. 
		 * 	More efficient than using the other sound classes for longer sounds.
		 * 
		 * @param filename: the file to load
		 */
		static void loadMusic(const char* filename);

		/**
		 * Deletes sources and buffers.
		 * Also closes the sound file.
		 */
		static void cleanUp();

		/**
		 * Use this function after you run the play function
		 * Put this function in a loop of some kind. Maybe a while loop.
		 */
		static void updateBufferStream();

		/**
		 * @brief 
		 * 
		 * @return The static variable m_Source
		 */
		static ALint getSource();

	private:
		static ALuint m_Source;
		static const int BUFFER_SAMPLES = 8192;
		static const int NUM_BUFFERS = 4;
		static ALuint m_Buffers[NUM_BUFFERS];
		static SNDFILE* m_SndFile;
		static SF_INFO m_Sfinfo;
		static short* m_Membuf;
		static ALenum m_Format;
	};
}

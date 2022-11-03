#pragma once
#include <AL/al.h>
#include <sndfile.h>

#define MP_LOAD wase::sound::MusicBuffer::loadMusic
#define MP_PLAY wase::sound::MusicBuffer::play
#define MP_UPDATE wase::sound::MusicBuffer::updateBufferStream
#define MP_CLEAN wase::sound::MusicBuffer::cleanUp

namespace wase::sound
{
	class MusicBuffer
	{
	public:
		static void play();
		static void loadMusic(const char* filename);
		static void cleanUp();

		static void updateBufferStream();

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

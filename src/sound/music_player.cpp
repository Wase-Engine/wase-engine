#include <cstddef>
#include <malloc.h>
#include <AL/alext.h>
#include "music_player.h"

namespace wase::sound
{
	const int MusicPlayer::BUFFER_SAMPLES = 8192;
	const int MusicPlayer::NUM_BUFFERS = 4;
	ALuint MusicPlayer::m_Source = 0;
	ALuint MusicPlayer::m_Buffers[NUM_BUFFERS];
	SNDFILE* MusicPlayer::m_SndFile;
	SF_INFO MusicPlayer::m_Sfinfo;
	short* MusicPlayer::m_Membuf;
	ALenum MusicPlayer::m_Format;

	void MusicPlayer::play()
	{
		ALsizei i;

		// clear any al errors
		alGetError();

		/* Rewind the source position and clear the buffer queue */
		alSourceRewind(m_Source);
		alSourcei(m_Source, AL_BUFFER, 0);

		/* Fill the buffer queue */
		for (i = 0; i < NUM_BUFFERS; i++)
		{
			/* Get some data to give it to the buffer */
			sf_count_t slen = sf_readf_short(m_SndFile, m_Membuf, BUFFER_SAMPLES);
			if (slen < 1) break;

			slen *= m_Sfinfo.channels * (sf_count_t)sizeof(short);
			alBufferData(m_Buffers[i], m_Format, m_Membuf, (ALsizei)slen, m_Sfinfo.samplerate);
		}
		if (alGetError() != AL_NO_ERROR)
		{
			throw("Error buffering for playback");
		}

		/* Now queue and start playback! */
		alSourceQueueBuffers(m_Source, i, m_Buffers);
		alSourcePlay(m_Source);
		if (alGetError() != AL_NO_ERROR)
		{
			throw("Error starting playback");
		}

	}

	void MusicPlayer::loadMusic(const char* filename)
	{
		alGenSources(1, &m_Source);
		alGenBuffers(NUM_BUFFERS, m_Buffers);

		std::size_t frame_size;

		m_SndFile = sf_open(filename, SFM_READ, &m_Sfinfo);
		if (!m_SndFile)
		{
			throw("could not open provided music file -- check path");
		}

		/* Get the sound format, and figure out the OpenAL format */
		if (m_Sfinfo.channels == 1)
			m_Format = AL_FORMAT_MONO16;
		else if (m_Sfinfo.channels == 2)
			m_Format = AL_FORMAT_STEREO16;
		else if (m_Sfinfo.channels == 3)
		{
			if (sf_command(m_SndFile, SFC_WAVEX_GET_AMBISONIC, NULL, 0) == SF_AMBISONIC_B_FORMAT)
				m_Format = AL_FORMAT_BFORMAT2D_16;
		}
		else if (m_Sfinfo.channels == 4)
		{
			if (sf_command(m_SndFile, SFC_WAVEX_GET_AMBISONIC, NULL, 0) == SF_AMBISONIC_B_FORMAT)
				m_Format = AL_FORMAT_BFORMAT3D_16;
		}
		if (!m_Format)
		{
			sf_close(m_SndFile);
			m_SndFile = NULL;
			throw("Unsupported channel count from file");
		}

		frame_size = ((size_t)BUFFER_SAMPLES * (size_t)m_Sfinfo.channels) * sizeof(short);
		m_Membuf = static_cast<short*>(malloc(frame_size));

	}

	void MusicPlayer::cleanUp()
	{
		alDeleteSources(1, &m_Source);

		if (m_SndFile)
			sf_close(m_SndFile);

		m_SndFile = nullptr;

		free(m_Membuf);

		alDeleteBuffers(NUM_BUFFERS, m_Buffers);
	}

	void MusicPlayer::updateBufferStream()
	{
		ALint processed, state;

		// clear error 
		alGetError();
		// Get relevant source info 
		alGetSourcei(m_Source, AL_SOURCE_STATE, &state);
		alGetSourcei(m_Source, AL_BUFFERS_PROCESSED, &processed);
		if (alGetError() != AL_NO_ERROR)
		{
			throw("error checking music source state");
		}

		// Unqueue and handle each processed buffer
		while (processed > 0)
		{
			ALuint bufid;
			sf_count_t slen;

			alSourceUnqueueBuffers(m_Source, 1, &bufid);
			processed--;

			// Read the next chunk of data, refill the buffer, and queue it
			// back on the source
			slen = sf_readf_short(m_SndFile, m_Membuf, BUFFER_SAMPLES);
			if (slen > 0)
			{
				slen *= m_Sfinfo.channels * (sf_count_t)sizeof(short);
				alBufferData(bufid, m_Format, m_Membuf, (ALsizei)slen,
					m_Sfinfo.samplerate);
				alSourceQueueBuffers(m_Source, 1, &bufid);
			}
			if (alGetError() != AL_NO_ERROR)
			{
				throw("error buffering music data");
			}
		}

		// Make sure the source hasn't underrun 
		if (state != AL_PLAYING && state != AL_PAUSED)
		{
			ALint queued;

			// If no buffers are queued, playback is finished 
			alGetSourcei(m_Source, AL_BUFFERS_QUEUED, &queued);
			if (queued == 0)
				return;

			alSourcePlay(m_Source);
			if (alGetError() != AL_NO_ERROR)
			{
				throw("error restarting music playback");
			}
		}

	}

	ALint MusicPlayer::getSource()
	{
		return m_Source;
	}
}
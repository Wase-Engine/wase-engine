#include <climits>

#include <sndfile.h>

#include <audio/sound_buffer.h>
#include <debugging/log.h>
#include <debugging/open_al_check.h>

namespace wase::audio
{
	SoundBuffer::SoundBuffer(const char* path)
	{
		SF_INFO sfinfo;
		SNDFILE* sndfile = sf_open(path, SFM_READ, &sfinfo);
		if (!sndfile)
		{
			WASE_CORE_WARN("Could not open audio in {0}: {1}", path, sf_strerror(sndfile));
			return;
		}
		if (sfinfo.frames < 1 || sfinfo.frames >(sf_count_t)(INT_MAX / sizeof(short)) / sfinfo.channels)
		{
			WASE_CORE_WARN("Bad sample count in {0} ({1})", path, sfinfo.frames);
			sf_close(sndfile);
			return;
		}

		short* membuf = static_cast<short*>(malloc((size_t)(sfinfo.frames * sfinfo.channels) * sizeof(short)));

		sf_count_t num_frames = sf_readf_short(sndfile, membuf, sfinfo.frames);
		if (num_frames < 1)
		{
			free(membuf);
			sf_close(sndfile);
			WASE_CORE_WARN("Failed to read samples in {0} ({1})", path, num_frames);
			return;
		}

		ALsizei num_bytes = (ALsizei)(num_frames * sfinfo.channels) * (ALsizei)sizeof(short);

		OPEN_AL_CHECK(alGenBuffers(1, &m_Buffer));
		OPEN_AL_CHECK(alBufferData(m_Buffer, sfinfo.channels > 1 ? AL_FORMAT_STEREO16 : AL_FORMAT_MONO16, membuf, num_bytes, sfinfo.samplerate));

		free(membuf);
		sf_close(sndfile);
	}

	SoundBuffer::~SoundBuffer()
	{
		OPEN_AL_CHECK(alDeleteBuffers(1, &m_Buffer));
	}

	ALuint SoundBuffer::getID() const
	{
		return m_Buffer;
	}
}
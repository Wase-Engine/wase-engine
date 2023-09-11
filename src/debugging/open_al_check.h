#pragma once

#include <AL/al.h>

#include <debugging/log.h>

#define OPEN_AL_CHECK(call) { \
    call; \
    ALenum error = alGetError(); \
    if (error != AL_NO_ERROR) { \
        handleOpenALError(error, #call, __FILE__, __LINE__); \
    } \
}

inline void handleOpenALError(ALenum error, const char* function, const char* file, int line)
{
	WASE_CORE_WARN("OpenAL Error ({0} - {1}:{2}): {3}", function, file, line, alGetString(error));
}
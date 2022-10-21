#include "sound_device.h"
#include <al.h>
#include <stdio.h>
#include <vector>

namespace wase::sound
{
    static SoundDevice* _instance = nullptr;

    SoundDevice* SoundDevice::get()
    {
        init();
	    return _instance;
    }

    void SoundDevice::init()
    {
        if (_instance == nullptr)
            _instance = new SoundDevice();
    }

    /// <summary>
/// Gets the listeners current locaiton.
/// </summary>
/// <param name="x">return value x</param>
/// <param name="y">return value y</param>
/// <param name="z">return value z</param>
void SoundDevice::GetLocation(float& x, float& y, float& z)
{
	alGetListener3f(AL_POSITION, &x, &y, &z);
}

/// <summary>
/// Gets the current listener Orientation as 'at' and 'up'
/// </summary>
/// <param name="ori"> Return value: Must be a float array with 6 slots available ex: float myvar[6]</param>
void SoundDevice::GetOrientation(float& ori)
{
	alGetListenerfv(AL_ORIENTATION, &ori);
}

/// <summary>
/// Gets the current volume of our listener.
/// </summary>
/// <returns>current volume</returns>
float SoundDevice::GetGain()
{
	float curr_gain;
	alGetListenerf(AL_GAIN, &curr_gain);
	return curr_gain;
}

/// <summary>
/// Sets the location of our listener
/// </summary>
/// <param name="x"></param>
/// <param name="y"></param>
/// <param name="z"></param>
void SoundDevice::SetLocation(const float& x, const float& y, const float& z)
{
	alListener3f(AL_POSITION, x, y, z);
}

/// <summary>
/// Sets the orientation of our listener using 'look at' (or foward vector) and 'up' direction
/// </summary>
/// <param name="atx"></param>
/// <param name="aty"></param>
/// <param name="atz"></param>
/// <param name="upx"></param>
/// <param name="upy"></param>
/// <param name="upz"></param>
void SoundDevice::SetOrientation(const float& atx, const float& aty, const float& atz, const float& upx, const float& upy, const float& upz)
{
	std::vector<float> ori;
	ori.push_back(atx);
	ori.push_back(aty);
	ori.push_back(atz);
	ori.push_back(upx);
	ori.push_back(upy);
	ori.push_back(upz);
	alListenerfv(AL_ORIENTATION, ori.data());
}

/// <summary>
/// Sets the master volume of our listeners. capped between 0 and 5 for now.
/// </summary>
/// <param name="val"></param>
void SoundDevice::SetGain(const float& val)
{
	// clamp between 0 and 5
	float newVol = val;
	if (newVol < 0.f)
		newVol = 0.f;
	else if (newVol > 5.f)
		newVol = 5.f;

	alListenerf(AL_GAIN, newVol);
}

    SoundDevice::SoundDevice()
    {
        m_ALCDevice = alcOpenDevice(nullptr); // nullptr = get defualt device.
        if (!m_ALCDevice) throw("Failed to get sound device.");
        
        m_ALCContext = alcCreateContext(m_ALCDevice, nullptr); // Make context.
        if (!m_ALCContext) throw("Failed to set sound context.");

        if (!alcMakeContextCurrent(m_ALCContext)) // Make context current.
            throw("Failed to make context current.");

        const ALCchar* name = nullptr;
        if (alcIsExtensionPresent(m_ALCDevice, "ALC_ENUMERATE_ALL_EXT"))
            name = alcGetString(m_ALCDevice, ALC_ALL_DEVICES_SPECIFIER);

        if (!name || alcGetError(m_ALCDevice) != AL_NO_ERROR)
            name = alcGetString(m_ALCDevice, ALC_DEVICE_SPECIFIER);
        printf("Opened \"%s\"\n", name);
    }

    SoundDevice::~SoundDevice()
    {
        if (!alcMakeContextCurrent(nullptr))
            throw("Failed to set context to nullptr.");

        alcDestroyContext(m_ALCContext);
        if (m_ALCContext) 
            throw("failed to unset SoundDevice.m_ALCContext during close");

        if (!alcCloseDevice(m_ALCDevice))
            throw("Failed to close sound device");
    }
}
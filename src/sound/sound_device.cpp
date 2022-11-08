#include <stdio.h>
#include <vector>
#include <cstring>
#include <al.h>
#include "sound_device.h"

namespace wase::sound
{
    ALCdevice* SoundDevice::m_ALCDevice = nullptr;
    ALCcontext* SoundDevice::m_ALCContext = nullptr;

    void SoundDevice::listAudioDevices(const ALCchar *devices)
    {
        const ALCchar *device = devices, *next = devices + 1;
        size_t len = 0;

        fprintf(stdout, "Devices list:\n");
        fprintf(stdout, "----------\n");
        while (device && *device != '\0' && next && *next != '\0') {
                fprintf(stdout, "%s\n", device);
                len = strlen(device);
                device += (len + 1);
                next += (len + 2);
        }
        fprintf(stdout, "----------\n");
    }

    void SoundDevice::init()
    {
        ALboolean enumeration;

        enumeration = alcIsExtensionPresent(NULL, "ALC_ENUMERATION_EXT");
        if (enumeration == AL_TRUE)
        {
            listAudioDevices(alcGetString(NULL, ALC_DEVICE_SPECIFIER));
        }

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

    math::Vector3 SoundDevice::getLocation()
    {
        math::Vector3 vec(0, 0, 0);
        alGetListener3f(AL_POSITION, &vec.x, &vec.y, &vec.z);

        return vec;
    }

    float SoundDevice::getOrientation()
    {
        float ori;
        alGetListenerfv(AL_ORIENTATION, &ori);
        return ori;
    }

    float SoundDevice::getGain()
    {
        float curr_gain;
        alGetListenerf(AL_GAIN, &curr_gain);
        return curr_gain;
    }

    void SoundDevice::setLocation(math::Vector3 location)
    {
        alListener3f(AL_POSITION, location.x, location.y, location.z);
    }

    void SoundDevice::setOrientation(math::Vector3 atVector, math::Vector3 upVector)
    {
        std::vector<float> ori;
        ori.push_back(atVector.x);
        ori.push_back(atVector.y);
        ori.push_back(atVector.z);
        ori.push_back(upVector.x);
        ori.push_back(upVector.y);
        ori.push_back(upVector.z);
        alListenerfv(AL_ORIENTATION, ori.data());
    }

    void SoundDevice::setGain(const float& val)
    {
        // clamp between 0 and 5
        float newVol = val;
        if (newVol < 0.f)
            newVol = 0.f;
        else if (newVol > 5.f)
            newVol = 5.f;

        alListenerf(AL_GAIN, newVol);
    }

    void SoundDevice::cleanUp()
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
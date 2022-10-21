#pragma once
#include <alc.h>

#define SD_INIT wase::sound::SoundDevice::init()
#define LISTENER wase::sound::SoundDevice::get()

namespace wase::sound
{
    class SoundDevice
    {
    public:
        static SoundDevice* get();
        static void init();

        void GetLocation(float &x, float& y, float& z);
	    void GetOrientation(float &ori);
	    float GetGain();

	    void SetLocation(const float& x, const float& y, const float& z);
	    void SetOrientation(
		const float& atx, const float& aty, const float& atz,
		const float& upx, const float& upy, const float& upz);
	    void SetGain(const float& val);

        ~SoundDevice();
    private:
        SoundDevice();
        
        ALCdevice* m_ALCDevice;
        ALCcontext* m_ALCContext;
    };
}
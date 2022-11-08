#pragma once
#include <alc.h>
#include <math/vector3.h>

namespace wase::sound
{
    class SoundDevice
    {
    public:
        /**
         *  Lists all audio devices.
         */
        static void list_audio_devices(const ALCchar *devices);

        /**
         * Initializes the sound device.
         */
        static void init();

        /**
         * Gets the listener's current locaiton
         * 
         * @return the listener's current location
         */
        static math::Vector3 getLocation();

        /**
         * Gets the current listener Orientation as 'at' and 'up'
         * 
         * @return float array with 6 slots available example: float myvar[6]
         */
	    static float getOrientation();

        /**
         * Gets the current volume of our listener
         * 
         * @return current volume
         */
	    static float getGain();

        /**
         * Sets the location of our listener
         */
	    static void setLocation(math::Vector3 location);

        /**
         * Sets the orientation of our listener using 'look at' (or foward vector) and 'up' direction
         */
	    static void setOrientation(math::Vector3 atVector, math::Vector3 upVector);

        /**
         * Sets the master volume of our listeners. capped between 0 and 5 for now.
         */
	    static void setGain(const float& val);

        /**
         * Sets m_ALCContext to nullptr, destroys m_ALCContext, and closes m_ALCDevice
         */
        static void cleanUp();

    private:
        SoundDevice();
        
        static ALCdevice* m_ALCDevice;
        static ALCcontext* m_ALCContext;
    };
}
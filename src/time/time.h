#pragma once

namespace wase::time
{
	class Time final
	{
	public:
		/**
		 * Set the delta time.
		 * 
		 * @param deltaTime: the delta time
		 */
		static void setDeltaTime(const float time);
		
		/**
		 * Get the delta time.
		 * 
		 * @return the delta time
		 */
		static float getDeltaTime();

	private:
		Time() = default;
		
		static float m_DeltaTime;
	};
}
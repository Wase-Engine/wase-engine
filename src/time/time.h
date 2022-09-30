#pragma once

namespace wase::time
{
	class Time final
	{
	public:
		/**
		 * Update the time manager
		 */
		static void update();
		
		/**
		 * Get the delta time.
		 * 
		 * @return the delta time
		 */
		static float getDeltaTime();

	private:
		Time() = default;
		
		static float m_DeltaTime;
		static float m_LastFrameTime;
	};
}
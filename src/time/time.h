#pragma once

namespace wase::time
{
	class Time
	{
	public:
		/**
		 * Update the time manager
		 */
		void update();
		
		/**
		 * Get the delta time.
		 * 
		 * @return the delta time
		 */
		float getDeltaTime();

	private:		
		float m_DeltaTime = 0.0f;
		float m_LastFrameTime = 0.0f;
	};
}
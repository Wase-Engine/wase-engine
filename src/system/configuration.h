#pragma once

namespace wase::system
{
	struct Configuration
	{
		const char* m_Name = "Wase Engine";
		unsigned int m_WindowWidth = 1280, m_WindowHeight = 720;
		bool m_Vsync = true;
	};
}
#pragma once

#include <memory>
#include <string>
#include <SDL.h>

namespace wase
{
	class Engine
	{
	public:
		Engine(const Engine&) = delete;

		static void init(const char* title, const int x, const int y, const unsigned int w, const unsigned int h, const Uint32 flags);
		static void run(const char* sceneName);
		static void quit();
		static void terminate(const std::string& message);

	private:
		bool m_IsRunning = false;

	private:
		Engine() {}

		void events();
		void update(float dt);
		void render();
		void destroy();

		void iInit(const char* title, const int x, const int y, const unsigned int w, const unsigned int h, const Uint32 flags);
		void iRun(const char* sceneName);
		void iQuit();
		void iTerminate(const std::string& message) const;

		static Engine& get();
	};
}
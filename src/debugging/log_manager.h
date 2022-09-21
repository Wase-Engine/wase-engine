#pragma once

#include <memory.h>

#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>

namespace wase::debugging
{
	class LogManager
	{
	public:
		static void initialize();
		static void shutdown();

		/**
		 * Get the core logger.
		 */
		static std::shared_ptr<spdlog::logger>& getCoreLogger();

	private:
		static std::shared_ptr<spdlog::logger> m_CoreLogger;
	};
}
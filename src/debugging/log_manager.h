#pragma once

#include <memory.h>

#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>

namespace wase::debugging
{
	class LogManager final
	{
	public:
		/**
		 * Initialize the logger
		 */
		static void initialize();

		/**
		 * Shut down the logger
		 */
		static void shutdown();

		/**
		 * Get the core logger.
		 * 
		 * @return the core logger
		 */
		static std::shared_ptr<spdlog::logger>& getCoreLogger();

	private:
		LogManager() = default;

		static std::shared_ptr<spdlog::logger> m_CoreLogger;
	};
}
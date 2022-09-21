#include <memory>

#include <debugging/log_manager.h>

namespace wase::debugging
{
	std::shared_ptr<spdlog::logger> LogManager::m_CoreLogger;

	void LogManager::initialize()
	{
		spdlog::set_pattern("%^[%T] %n: %v%$");
		
		m_CoreLogger = spdlog::stdout_color_mt("WASE");
		m_CoreLogger->set_level(spdlog::level::trace);
	}

	void LogManager::shutdown()
	{
		spdlog::shutdown();
	}

	std::shared_ptr<spdlog::logger>& LogManager::getCoreLogger()
	{
		return m_CoreLogger;
	}
}
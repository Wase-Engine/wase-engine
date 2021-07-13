#pragma once

#include <string>

namespace log_utils
{
	std::string timestamp();
	void info(const std::string& message);
	void success(const std::string& message);
	void error(const std::string& message);
}
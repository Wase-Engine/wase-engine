#pragma once

#include <string>

namespace log_utils
{
	std::string timestamp();
	void info(const char* message);
	void success(const char* message);
	void error(const char* message);
}
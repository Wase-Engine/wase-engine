#define _CRT_SECURE_NO_WARNINGS

#include "log_utils.h"

#include <iostream>
#include <ctime>
#include <sstream>
#include <iomanip>

namespace log_utils
{
	std::string timestamp()
	{
		std::stringstream resultStream;
		std::time_t rawTime = std::time(nullptr);
		std::tm *localTime = std::localtime(&rawTime);

		resultStream << std::put_time(localTime, "%T");

		return resultStream.str();
	}

	void info(const char* message)
	{
		std::cout << "[" << timestamp() << " INFO] " << message << "\n";
	}

	void success(const char* message)
	{
		std::cout << "\u001b[32m" << "[" << timestamp() << " SUCCESS] " << message << "\n\u001b[0m";
	}

	void error(const char* message)
	{
		std::cerr << "\u001b[31m" << "[" << timestamp() << " ERROR] " << message << "\n\u001b[0m";
	}
}
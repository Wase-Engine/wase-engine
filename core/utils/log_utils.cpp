#define _CRT_SECURE_NO_WARNINGS
#include "log_utils.h"

#include <iostream>
#include <time.h>
#include <sstream>

namespace log_utils
{
	void info(const char* message)
	{
		std::cout << "[INFO] " << message << "\n";
	}

	void success(const char* message)
	{
		std::cout << "\u001b[32m[SUCCESS] " << message << "\n\u001b[0m";
	}

	void error(const char* message)
	{
		std::cerr << "\u001b[31m[ERROR] " << message << "\n\u001b[0m";
	}
}
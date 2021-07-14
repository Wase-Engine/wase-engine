#define _CRT_SECURE_NO_WARNINGS

#include "log_utils.h"

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
}
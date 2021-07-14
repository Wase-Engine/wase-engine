#pragma once

#include <string>
#include <iostream>

namespace log_utils
{
    std::string timestamp();

    template <typename typeOfLog>
    void info(const typeOfLog& message)
    {
        std::cout << "[" << timestamp() << " INFO] " << message << "\n";
    }

    template <typename typeOfLog>
    void success(const typeOfLog& message)
    {
        std::cout << "\u001b[32m" << "[" << timestamp() << " SUCCESS] " << message << "\n\u001b[0m";
    }

    template <typename typeOfLog>
    void error(const typeOfLog& message)
    {
        std::cerr << "\u001b[31m" << "[" << timestamp() << " ERROR] " << message << "\n\u001b[0m";
    }
}
#include "Logger.h"

#include <iostream>

void Logger::LogMessage(const std::string& message)
{
    std::cout << message;
}

void Logger::LogMessage(const std::vector<std::string>& lines)
{
    std::string fullMsg{};
    for (const std::string& msg : lines)
    {
        fullMsg += msg;
        fullMsg += "\n";
    }
    LogMessage(fullMsg);
}

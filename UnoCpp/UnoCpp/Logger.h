#pragma once
#include <string>
#include <vector>

class Logger
{
public:
    static void LogMessage(const std::string& message);
    static void LogMessage(const std::vector<std::string>& lines);
};

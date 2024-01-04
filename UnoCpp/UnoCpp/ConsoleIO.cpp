#include "ConsoleIO.h"

#include <iostream>

void ConsoleIO::LogMessage(const std::string& message)
{
    std::cout << message;
}

void ConsoleIO::LogMessage(const std::vector<std::string>& lines)
{
    std::string fullMsg{};
    for (const std::string& msg : lines)
    {
        fullMsg += msg;
        fullMsg += "\n";
    }
    LogMessage(fullMsg);
}

void ConsoleIO::Clear()
{
    system("cls");
}

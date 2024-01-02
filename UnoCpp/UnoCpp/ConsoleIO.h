#pragma once
#include <iostream>
#include <string>
#include <vector>

class ConsoleIO
{
public:
    static void LogMessage(const std::string& message);
    static void LogMessage(const std::vector<std::string>& lines);
    
    template<typename T>
    static T GetInput(const std::string& msg);
};

template <typename T>
T ConsoleIO::GetInput(const std::string& msg)
{
    T input{};
    std::cout << msg;
    std::cin >> std::ws >> input;
    if(std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore();
        return GetInput<T>(msg);
    }
    return input;
}
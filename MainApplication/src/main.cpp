#include "Application.hpp"
#include <iostream>

int main()
{
    try
    {
        Application snake;
        snake.run();
    }
    catch (std::string exception)
    {
        std::cerr << exception;
    }
    return 0;
}
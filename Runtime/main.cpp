#include <exception>
#include <iostream>
#include "engine/Core.hpp"

int main()
{
    Engine::Core core;

    try
    {
        core.mainLoop();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }   

    return 0;
}
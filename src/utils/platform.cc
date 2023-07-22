#include "GLL/platform.hh"

void GLL::display_platform()
{
    #ifdef __linux__
        std::cout << "Running on Linux" << std::endl;
    #elif _WIN32
        std::cout << "Running on Windows" << std::endl;
    #elif __APPLE__
        std::cout << "Running on Apple OS" << std::endl;
    #else
        std::cout << "Running on an Unsupported Platform" << std::endl;
    #endif
}
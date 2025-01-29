#include <iostream>
#include <SDL2/SDL.h>

#include "App.hpp"
#include "Core.hpp"

int main()
{
    SDL::App app;

    SDL_DisplayMode dispMode;

    if (SDL_GetCurrentDisplayMode(0, &dispMode) != 0)
    {
        std::cerr << "Error while getting display size: " << SDL_GetError() << std::endl;
        return 1;
    }
    //SDL_SetWindowSize(app.getWindow(), dispMode.w, dispMode.h);

    mainLoop(app);
 
    return 0;
}

#include <iostream>
#include <SDL2/SDL.h>

#include "Window.hpp"
#include "Core.hpp"

int main()
{
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0)
    {
        std::cout << "Error while initializing SDL : " << SDL_GetError() << std::endl;
        throw "Init error";
    }

    SDL_DisplayMode dispMode;
    SDL_GetCurrentDisplayMode(0, &dispMode);

    Editor::Window win(dispMode.w, dispMode.h, "Editor");

    mainLoop(win);

    SDL_Quit();

    return 0;
}

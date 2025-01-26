#include <iostream>
#include <SDL2/SDL_hints.h>

#include "Window.hpp"

using namespace Editor;

Window::Window(int x, int y, const std::string &name)
{
    _window = SDL_CreateWindow(
        name.c_str(),
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        x,
        y,
        SDL_WINDOW_SHOWN
    );
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "0");
    _renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    if (_window == NULL)
    {
        std::cout << "Error while creating the window : " << SDL_GetError() << std::endl;
        throw "Window error";
    }
}

Window::~Window()
{
    if (_window)
    {
        SDL_DestroyWindow(_window);
    }
    if (_renderer)
    {
        SDL_DestroyRenderer(_renderer);
    }
}

SDL_Window *Window::getWindow()
{
    return _window;
}

SDL_Renderer *Window::getRenderer()
{
    return _renderer;
}

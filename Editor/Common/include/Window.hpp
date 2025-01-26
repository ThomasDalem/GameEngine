#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <string>
#include <SDL2/SDL_video.h>
#include <SDL2/SDL_render.h>

namespace Editor
{
    class Window
    {
    public:
        Window(int width, int height, const std::string &name);
        ~Window();

        SDL_Window *getWindow();
        SDL_Renderer *getRenderer();

    private:
        SDL_Window *_window;
        SDL_Renderer * _renderer;
    };
}

#endif

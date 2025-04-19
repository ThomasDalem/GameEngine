#ifndef APP_HPP
#define APP_HPP

#include <SDL2/SDL_video.h>
#include <SDL_opengl.h>
#include <GL/gl.h>

namespace SDL {
    class App {
    public:
        App(uint16_t screenWidth = 800, uint16_t screenHeight = 400);
        ~App();

        SDL_Window *getWindow();
        SDL_Surface *getSurface();
        SDL_GLContext &getContext();

        uint16_t getScreenWidth() const noexcept;
        uint16_t getScreenHeight() const noexcept;

    private:
        void initOpenGL();

    private:
        SDL_Window *_window;
        SDL_Surface *_surface;
        SDL_GLContext _glContext;
        uint16_t _screenWidth;
        uint16_t _screenHeight;
    };
}

#endif // APP_HPP
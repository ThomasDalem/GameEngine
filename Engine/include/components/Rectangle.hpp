#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include <SDL2/SDL_pixels.h>
#include "Rect.hpp"

namespace Engine
{
    struct Rectangle
    {
        RectI rect;
        SDL_Color color = {255, 255, 255, 50};
        bool hidden = false;
    };
}

#endif

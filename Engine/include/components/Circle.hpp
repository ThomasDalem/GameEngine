#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "Color.hpp"

namespace Engine
{
    struct Circle
    {
        Color color;
        float x;
        float y;
        int radius;
        bool filled;
        bool hidden;
    };
}

#endif

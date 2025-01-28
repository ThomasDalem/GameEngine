#ifndef LINE_HPP
#define LINE_HPP

#include "Vec.hpp"

namespace Engine
{
    struct Line
    {
        Vec2f a;
        Vec2f b;
        bool hidden = false;
    };
}

#endif

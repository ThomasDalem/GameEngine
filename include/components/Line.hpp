#ifndef LINE_HPP
#define LINE_HPP

#include "utils/Vec.hpp"

struct Line
{
    Vec2f a;
    Vec2f b;
    bool hidden = false;
};

#endif // LINE_HPP
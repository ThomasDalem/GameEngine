#ifndef POLYGON_HPP
#define POLYGON_HPP

#include <vector>
#include "Color.hpp"

namespace Engine
{
    struct Polygon
    {
        std::vector<short int> xs;
        std::vector<short int> ys;
        Color color;
    };
}

#endif

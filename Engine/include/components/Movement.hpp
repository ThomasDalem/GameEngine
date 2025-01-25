#ifndef MOVEMENT_HPP
#define MOVEMENT_HPP

#include "utils/Vec.hpp"

namespace Engine
{
    struct Movement
    {
        Vec2f direction;
        float speed;
        bool move;
    };
}

#endif

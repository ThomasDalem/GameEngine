#ifndef POSITION_HPP
#define POSITION_HPP

#include "Vec.hpp"

//using Position = Vec2f;

namespace Engine
{
    enum PositionType
    {
        ABSOLUTE,
        RELATIVE
    };

    struct Position
    {
        float x;
        float y;
        PositionType type = ABSOLUTE;

        // Position operators
        Position &operator+=(const Position &other)
        {
            x += other.x;
            y += other.y;
            return *this;
        }
        Position &operator-=(const Position &other)
        {
            x -= other.x;
            y -= other.y;
            return *this;
        }

        // Vec2 operators
        template <typename T>
        Position operator=(const Vec2<T> &other)
        {
            x = other.x;
            y = other.y;
            return *this;
        }
        template <typename T>
        Position &operator+=(const Vec2<T> &other)
        {
            x += other.x;
            y += other.y;
            return *this;
        }
        template <typename T>
        Position operator+(const Vec2<T> &other)
        {
            return {x + other.x, y + other.y};
        }

        template <typename T>
        operator Vec2<T>()
        {
            return {static_cast<float>(x), static_cast<float>(y)};
        }
    };
}

#endif

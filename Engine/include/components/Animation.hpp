#ifndef ANIM_HPP
#define ANIM_HPP

#include <cstdint>
#include "Vec.hpp"

namespace Engine
{
    struct Animation
    {
        float startTime; // Current animation time since it started
        uint64_t duration;
        uint16_t curStep; // Current step of the animation
        uint16_t steps; // Number of steps of the animation
        Vec2i startPos;
        Vec2i spriteSize;
        bool playAnim; // Should the animation be played ?
    };
}

#endif

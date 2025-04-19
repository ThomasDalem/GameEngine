#ifndef SPRITE_HPP
#define SPRITE_HPP

#include <memory>
#include "Vec.hpp"
#include "Rect.hpp"

namespace Engine
{
    struct Sprite
    {
        Vec2f scale;
        RectI textureRect;
        RectF rect;
        //std::shared_ptr<SDL::Texture> texture;
        int alpha;
        float angle = 0.f;
        bool hidden = false;
    };
}

#endif

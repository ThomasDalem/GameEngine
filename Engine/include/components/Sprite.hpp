#ifndef SPRITE_HPP
#define SPRITE_HPP

#include <memory>
#include "Vec.hpp"
#include "Rect.hpp"
#include "Texture.hpp"

namespace Engine
{
    struct Sprite
    {
        bool hidden;
        Vec2f scale;
        RectI textureRect;
        RectF rect;
        float angle;
        SDL_RendererFlip flip;
        std::shared_ptr<SDL::Texture> texture;
        int alpha;
    };
}

#endif

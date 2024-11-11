#ifndef SPRITE_HPP
#define SPRITE_HPP

#include <memory>
#include "utils/Vec.hpp"
#include "utils/Rect.hpp"
#include "SDL/Texture.hpp"

struct Sprite {
    bool hidden;
    Vec2f scale;
    RectI textureRect;
    RectF rect;
    float angle;
    std::unique_ptr<Vec2f> center;
    SDL_RendererFlip flip;
    std::shared_ptr<SDL::Texture> texture;
    int alpha;
};

#endif // SPRITE_HPP
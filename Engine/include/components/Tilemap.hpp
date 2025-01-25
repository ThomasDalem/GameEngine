#ifndef TILEMAP_HPP
#define TILEMAP_HPP

#include <vector>
#include <memory>
#include <unordered_map>
#include "utils/Rect.hpp"
#include "SDL/Texture.hpp"

namespace Engine
{
    enum TileType
    {
        EMPTY,
        ROAD,
        ROAD_MIDDLE,
        SIDE_WALK_UP,
        SIDE_WALK_DOWN,
        SIDE_WALK
    };

    inline std::unordered_map<TileType, Vec2i> TILES_POS = {
        {EMPTY, {0, 0}},
        {ROAD, {16, 0}}
    };

    struct Tilemap
    {
        std::vector<TileType> map;
        std::shared_ptr<SDL::Texture> texture;
        std::size_t x;
        std::size_t y;
        int tileWidth;
        int tileHeight;
    };
}

#endif
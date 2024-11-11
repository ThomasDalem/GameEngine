#ifndef ITEMS_DEFS_HPP
#define ITEMS_DEFS_HPP

#include <string>
#include "SDL/Texture.hpp"

enum ItemID
{
    NONE,
    GUN,
    BANDAGE
};

struct ItemData
{
    std::string name;
    std::string description;
    SDL::Texture &texure;
    ItemID id;
};

#endif // ITEMS_DEFS_HPP
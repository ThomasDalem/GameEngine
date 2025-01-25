#ifndef RELATIONSHIP_HPP
#define RELATIONSHIP_HPP

#include <vector>
#include "entt.hpp"

namespace Engine
{
    struct Parent
    { 
        entt::entity entity {entt::null};
    };

    struct Children
    {
        std::vector<entt::entity> entities;
    };
}

#endif // RELATIONSHIP_HPP
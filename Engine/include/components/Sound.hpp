#ifndef SOUND_HPP
#define SOUND_HPP

#include "SDL/Chunk.hpp"

namespace Engine
{
    struct Sound
    {
        SDL::MixChunk *chunk;
    };
}

#endif

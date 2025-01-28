#ifndef SOUND_HPP
#define SOUND_HPP

#include "Chunk.hpp"

namespace Engine
{
    struct Sound
    {
        SDL::MixChunk *chunk;
    };
}

#endif

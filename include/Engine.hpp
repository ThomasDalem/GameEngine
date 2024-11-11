#ifndef ENGINE_HPP
#define ENGINE_HPP

#include "utils/Vec.hpp"
#include "utils/Rect.hpp"

namespace Engine {
    class Camera : public RectI
    {
    };

    class Core
    {
    public:
        static Core &getInstance()
        {
            static Core core;
            return core;
        }

        Core(const Core &other) = delete;
        Core &operator=(const Core &other) = delete;
        ~Core() = default;

        Camera &getCamera();

    private:
        Core() = default;
        Camera _camera;
    };
}

#endif
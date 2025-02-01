#ifndef RECT_HPP
#define RECT_HPP

#include <ostream>
#include "Vec.hpp"

template<typename T>
struct Rect {
    T x;
    T y;
    T width;
    T height;

    void setPosition(const Vec2<T> &pos)
    {
        x = static_cast<int>(pos.x);
        y = static_cast<int>(pos.y);
    }
    Vec2<T> getPosition() const
    {
        return {static_cast<T>(x), static_cast<T>(y)};
    }

    template<typename U>
    Rect<T> operator=(const Rect<U> &other)
    {
        x = static_cast<U>(other.x);
        y = static_cast<U>(other.y);
        width = static_cast<U>(other.width);
        height = static_cast<U>(other.height);
        return *this;
    }

    operator SDL_Rect()
    {
        return {static_cast<int>(x), static_cast<int>(y), static_cast<int>(width), static_cast<int>(height)};
    }
};

template<typename T>
inline std::ostream &operator<< (std::ostream &os, const Rect<T> &rect)
{
    os << "x: " << rect.x
        << "\ty: " << rect.y
        << "\twidth: " << rect.width
        << "\theight: " << rect.height;
    return os;
}

template<typename T, typename P>
bool pointInRect(Rect<T> rect, P x, P y)
{
    return (x > rect.x && x < rect.x + rect.width) && (y > rect.y && y < rect.y + rect.height);
}

using RectI = Rect<int>;
using RectF = Rect<float>;
using RectD = Rect<double>;

#endif

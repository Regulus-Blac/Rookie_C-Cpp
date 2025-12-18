#pragma once
#include "Point.hpp"

namespace adas{

    class Direction final{
    public:
        static const Direction& GetDirection(const char heading) noexcept;
        Direction(const unsigned index, const char heading) noexcept;

    public:
        const Point& Move(void) const noexcept;
        const Direction& LeftOne(void) const noexcept;
        const Direction& RightOne(void) const noexcept;
        const char GetHeading(void) const noexcept; //  获取方向字符

    private:
        unsigned index; //  0 1 2 3
        char heading;   //  E S W N

    };
}
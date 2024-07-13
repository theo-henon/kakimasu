#pragma once

#include <cstdint>
#include <ostream>

namespace kakimasu::image
{
    struct Rgb24Color
    {
        uint8_t r;
        uint8_t g;
        uint8_t b;
    };

    std::ostream& operator<<(std::ostream& os, Rgb24Color color);
} // namespace kakimasu::image
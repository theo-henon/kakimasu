#pragma once

#include <stdexcept>

#include "image.hh"

namespace kakimasu::image
{
    template <typename ColorType>
    Image<ColorType>::Image(uint32_t width, uint32_t height)
        : AbstractImage(width, height)
    {}
} // namespace kakimasu::image
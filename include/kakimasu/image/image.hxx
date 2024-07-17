#pragma once

#include <stdexcept>

#include "image.hh"

namespace kakimasu::image
{
    template <typename ColorType>
    Image<ColorType>::Image(uint32_t width, uint32_t height)
    {
        if (width == 0 || height == 0)
            throw std::invalid_argument(
                "Image dimensions must be strictly positive");
        width_ = width;
        height_ = height;
    }

    template <typename ColorType>
    uint32_t Image<ColorType>::get_width() const
    {
        return width_;
    }

    template <typename ColorType>
    uint32_t Image<ColorType>::get_height() const
    {
        return height_;
    }
} // namespace kakimasu::image
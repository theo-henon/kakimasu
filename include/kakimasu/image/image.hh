#pragma once

#include <cstdint>

#include "abstract_image.hh"
#include "color.hh"

namespace kakimasu::image
{
    template <typename ColorType>
    class Image : public AbstractImage
    {
    public:
        Image(uint32_t width, uint32_t height);
        ~Image() override = default;

        virtual ColorType get_pixel(uint32_t x, uint32_t y) const = 0;
        virtual void set_pixel(uint32_t x, uint32_t y, ColorType color) = 0;
    };
} // namespace kakimasu::image

#include "image.hxx"

#pragma once

#include <cstdint>

#include "color.hh"

namespace kakimasu::image
{
    template <typename ColorType>
    class Image
    {
    public:
        Image(uint32_t width, uint32_t height);
        virtual ~Image() = default;

        [[nodiscard]] virtual uint32_t get_width() const;
        [[nodiscard]] virtual uint32_t get_height() const;
        virtual ColorType get_pixel(uint32_t x, uint32_t y) const = 0;
        virtual void set_pixel(uint32_t x, uint32_t y, ColorType color) = 0;

    private:
        uint32_t width_;
        uint32_t height_;
    };
} // namespace kakimasu::image

#include "image.hxx"

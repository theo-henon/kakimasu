#pragma once

#include "pixmap_image.hh"

namespace kakimasu::image
{
    class Rgb24Image : public PixmapImage<3, BitDepth::BITS_8>
    {
    public:
        Rgb24Image(uint32_t width, uint32_t height);
        ~Rgb24Image() override = default;

        [[nodiscard]] uint8_t get_red(uint32_t x, uint32_t y) const;
        [[nodiscard]] uint8_t get_green(uint32_t x, uint32_t y) const;
        [[nodiscard]] uint8_t get_blue(uint32_t x, uint32_t y) const;
        void set_red(uint32_t x, uint32_t y, uint8_t value);
        void set_green(uint32_t x, uint32_t y, uint8_t value);
        void set_blue(uint32_t x, uint32_t y, uint8_t value);
    };
} // namespace kakimasu::image
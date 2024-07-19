#pragma once

#include <vector>

#include "grayscale8_color.hh"
#include "image.hh"

namespace kakimasu::image
{
    class Grayscale8Image : public Image<Grayscale8Color>
    {
    public:
        Grayscale8Image(uint32_t width, uint32_t height);

        [[nodiscard]] Grayscale8Color get_pixel(uint32_t x,
                                                uint32_t y) const override;
        void set_pixel(uint32_t x, uint32_t y, Grayscale8Color color) override;

    private:
        std::vector<Grayscale8Color> pixels_;
    };
} // namespace kakimasu::image

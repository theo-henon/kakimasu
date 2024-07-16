#pragma once

#include <vector>

#include "image.hh"
#include "rgb24_color.hh"

namespace kakimasu::image
{
    class Rgb24Image : public Image<Rgb24Color>
    {
    public:
        Rgb24Image(uint32_t width, uint32_t height);
        ~Rgb24Image() override = default;

        [[nodiscard]] Rgb24Color get_pixel(uint32_t x, uint32_t y) const override;
        void set_pixel(uint32_t x, uint32_t y, Rgb24Color color) override;

    private:
        std::vector<Rgb24Color> pixels_;
    };
} // namespace kakimasu::image

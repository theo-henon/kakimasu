#pragma once

#include <vector>

#include "image.hh"

namespace kakimasu::image
{
    class BitmapImage : public Image<bool>
    {
    public:
        BitmapImage(uint32_t width, uint32_t height);
        ~BitmapImage() override = default;

        [[nodiscard]] bool get_pixel(uint32_t x, uint32_t y) const override;
        void set_pixel(uint32_t x, uint32_t y, bool color) override;

    private:
        std::vector<bool> pixels_;
    };
} // namespace kakimasu::image

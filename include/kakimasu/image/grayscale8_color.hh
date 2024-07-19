#pragma once

#include <cstdint>

#include "color.hh"

namespace kakimasu::image
{
    class Grayscale8Color : public Color<1, uint8_t>
    {
    public:
        Grayscale8Color();
        explicit Grayscale8Color(uint8_t scale);

        [[nodiscard]] int get_num_channels() const override;
        [[nodiscard]] uint8_t get_channel(int index) const override;
        void set_channel(int index, uint8_t value) override;
        [[nodiscard]] uint8_t get_scale() const;
        void set_scale(uint8_t value);

    private:
        uint8_t scale_;
    };
} // namespace kakimasu::image

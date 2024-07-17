#pragma once

#include <cstdint>
#include <ostream>

#include "color.hh"

namespace kakimasu::image
{
    class Rgb24Color : public Color<3, uint8_t>
    {
    public:
        Rgb24Color();
        Rgb24Color(uint8_t red, uint8_t green, uint8_t blue);
        ~Rgb24Color() override = default;

        [[nodiscard]] int get_num_channels() const override;
        [[nodiscard]] uint8_t get_channel(int index) const override;
        void set_channel(int index, uint8_t value) override;
        [[nodiscard]] uint8_t get_red() const;
        void set_red(uint8_t value);
        [[nodiscard]] uint8_t get_green() const;
        void set_green(uint8_t value);
        [[nodiscard]] uint8_t get_blue() const;
        void set_blue(uint8_t value);

        friend std::ostream& operator<<(std::ostream& os, const Rgb24Color& color);

    private:
        uint8_t red_;
        uint8_t green_;
        uint8_t blue_;
    };
} // namespace kakimasu::image

#pragma once

#include <cstdint>

namespace kakimasu::image
{
    class Image
    {
    public:
        Image(uint32_t width, uint32_t height);
        virtual ~Image() = default;

        uint32_t get_width() const;
        uint32_t get_height() const;
        virtual int get_bit_depth() const = 0;

    private:
        uint32_t width_;
        uint32_t height_;
    };
} // namespace kakimasu::image
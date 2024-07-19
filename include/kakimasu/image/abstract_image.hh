#pragma once

#include <cstdint>

namespace kakimasu::image
{
    class AbstractImage
    {
    public:
        AbstractImage(uint32_t width, uint32_t height);
        virtual ~AbstractImage() = default;

        [[nodiscard]] uint32_t get_width() const;
        [[nodiscard]] uint32_t get_height() const;

    private:
        uint32_t width_;
        uint32_t height_;
    };
} // namespace kakimasu::image

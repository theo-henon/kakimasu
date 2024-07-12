#pragma once

#include <cstdint>
#include <vector>

#include "bit_depth.hh"
#include "image.hh"

namespace kakimasu::image
{
    template <int NumChannels, BitDepth BDepth>
    class PixmapImage : public Image
    {
    public:
        PixmapImage(uint32_t width, uint32_t height);
        ~PixmapImage() override = default;

        [[nodiscard]] inline int get_bit_depth() const override;
        [[nodiscard]] inline int get_num_channels() const;

    protected:
        std::vector<uint8_t> bytes_;
    };
} // namespace kakimasu::image

#include "pixmap_image.hxx"
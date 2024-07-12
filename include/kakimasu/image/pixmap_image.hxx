#pragma once

#include "pixmap_image.hh"

namespace kakimasu::image
{

    template <int NumChannels, BitDepth BDepth>
    PixmapImage<NumChannels, BDepth>::PixmapImage(uint32_t width,
                                                  uint32_t height)
        : Image(width, height)
        , bytes_(width * height * NumChannels * static_cast<int>(BDepth) / 8)
    {}

    template <int NumChannels, BitDepth BDepth>
    inline int PixmapImage<NumChannels, BDepth>::get_num_channels() const
    {
        return NumChannels;
    }

    template <int NumChannels, BitDepth BDepth>
    inline int PixmapImage<NumChannels, BDepth>::get_bit_depth() const
    {
        return static_cast<int>(BDepth);
    }

} // namespace kakimasu::image
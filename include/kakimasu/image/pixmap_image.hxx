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
} // namespace kakimasu::image
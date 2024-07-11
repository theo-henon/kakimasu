#include <kakimasu/image/pixmap_image.hh>

namespace kakimasu::image
{
    template <int NumChannels, BitDepth BDepth>
    int PixmapImage<NumChannels, BDepth>::get_num_channels() const
    {
        return NumChannels;
    }

    template <int NumChannels, BitDepth BDepth>
    int PixmapImage<NumChannels, BDepth>::get_bit_depth() const
    {
        return static_cast<int>(BDepth);
    }
} // namespace kakimasu::image
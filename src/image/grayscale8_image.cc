#include <kakimasu/image/grayscale8_image.hh>

namespace kakimasu::image
{
    Grayscale8Image::Grayscale8Image(uint32_t width, uint32_t height)
        : PixmapImage<1, BitDepth::BITS_8>(width, height)
    {}

    uint8_t Grayscale8Image::get_scale(uint32_t x, uint32_t y) const
    {
        return bytes_[get_width() * y + x];
    }

    void Grayscale8Image::set_scale(uint32_t x, uint32_t y, uint8_t scale)
    {
        bytes_[get_width() * y + x] = scale;
    }

} // namespace kakimasu::image
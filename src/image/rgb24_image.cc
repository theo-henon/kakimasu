#include <kakimasu/image/rgb24_image.hh>

namespace kakimasu::image
{
    Rgb24Image::Rgb24Image(uint32_t width, uint32_t height)
        : PixmapImage<3, BitDepth::BITS_8>(width, height)
    {}

    uint8_t Rgb24Image::get_red(uint32_t x, uint32_t y) const
    {
        return bytes_[get_width() * y + x];
    }

    uint8_t Rgb24Image::get_green(uint32_t x, uint32_t y) const
    {
        return bytes_[get_width() * y + x + 1];
    }

    uint8_t Rgb24Image::get_blue(uint32_t x, uint32_t y) const
    {
        return bytes_[get_width() * y + x + 2];
    }

    void Rgb24Image::set_red(uint32_t x, uint32_t y, uint8_t value)
    {
        bytes_[get_width() * y + x] = value;
    }

    void Rgb24Image::set_green(uint32_t x, uint32_t y, uint8_t value)
    {
        bytes_[get_width() * y + x + 1] = value;
    }

    void Rgb24Image::set_blue(uint32_t x, uint32_t y, uint8_t value)
    {
        bytes_[get_width() * y + x + 2] = value;
    }
} // namespace kakimasu::image
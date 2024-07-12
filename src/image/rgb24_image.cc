#include <kakimasu/image/rgb24_image.hh>
#include "kakimasu/image/rgb24_color.hh"

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

    Rgb24Color Rgb24Image::get_color(uint32_t x, uint32_t y) const
    {
        size_t pixel_pos = get_width() * y + x;
        return { bytes_[pixel_pos], bytes_[pixel_pos + 1],
                 bytes_[pixel_pos + 2] };
    }

    void Rgb24Image::set_color(uint32_t x, uint32_t y, Rgb24Color color)
    {
        size_t pixel_pos = get_width() * y + x;
        bytes_[pixel_pos] = color.r;
        bytes_[pixel_pos + 1] = color.g;
        bytes_[pixel_pos + 2] = color.b;
    }

} // namespace kakimasu::image
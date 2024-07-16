#include <kakimasu/image/rgb24_image.hh>
#include <stdexcept>

namespace kakimasu::image
{
    Rgb24Image::Rgb24Image(uint32_t width, uint32_t height)
        : Image(width, height)
        , pixels_(width * height)
    {}

    Rgb24Color Rgb24Image::get_pixel(uint32_t x, uint32_t y) const
    {
        if (x >= get_width() || y >= get_height())
            throw std::out_of_range("Pixel out of range");
        return pixels_[get_width() * y + x];
    }

    void Rgb24Image::set_pixel(uint32_t x, uint32_t y, Rgb24Color color)
    {
        if (x >= get_width() || y >= get_height())
            throw std::out_of_range("Pixel out of range");
        pixels_[get_width() * y + x] = color;
    }
} // namespace kakimasu::image
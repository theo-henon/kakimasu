#include <kakimasu/image/grayscale8_image.hh>

namespace kakimasu::image
{
    Grayscale8Image::Grayscale8Image(uint32_t width, uint32_t height)
        : Image(width, height)
        , pixels_(width * height)
    {}

    Grayscale8Color Grayscale8Image::get_pixel(uint32_t x, uint32_t y) const
    {
        if (x >= get_width() || y >= get_height())
            throw std::out_of_range("Pixel out of range");
        return pixels_[y * get_width() + x];
    }

    void Grayscale8Image::set_pixel(uint32_t x, uint32_t y,
                                    Grayscale8Color color)
    {
        if (x >= get_width() || y >= get_height())
            throw std::out_of_range("Pixel out of range");
        pixels_[y * get_width() + x] = color;
    }
} // namespace kakimasu::image
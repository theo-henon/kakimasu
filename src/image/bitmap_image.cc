#include <kakimasu/image/bitmap_image.hh>

namespace kakimasu::image
{
    BitmapImage::BitmapImage(uint32_t width, uint32_t height)
        : Image(width, height)
        , pixels_(width * height)
    {}

    bool BitmapImage::get_pixel(uint32_t x, uint32_t y) const
    {
        return pixels_[y * get_width() + x];
    }

    void BitmapImage::set_pixel(uint32_t x, uint32_t y, bool color)
    {
        pixels_[y * get_width() + x] = color;
    }

} // namespace kakimasu::image
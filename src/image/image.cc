#include <cstdint>
#include <kakimasu/image/image.hh>

namespace kakimasu::image
{
    Image::Image(uint32_t width, uint32_t height)
        : width_(width)
        , height_(height)
    {}

    uint32_t Image::get_width() const
    {
        return width_;
    }

    uint32_t Image::get_height() const
    {
        return height_;
    }
} // namespace kakimasu::image
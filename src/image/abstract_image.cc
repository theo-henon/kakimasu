#include <kakimasu/image/abstract_image.hh>
#include <stdexcept>

namespace kakimasu::image
{
    AbstractImage::AbstractImage(uint32_t width, uint32_t height)
    {
        if (width == 0 || height == 0)
            throw std::invalid_argument(
                "Image dimensions must be strictly positive");
        width_ = width;
        height_ = height;
    }

    uint32_t AbstractImage::get_width() const
    {
        return width_;
    }

    uint32_t AbstractImage::get_height() const
    {
        return height_;
    }
} // namespace kakimasu::image
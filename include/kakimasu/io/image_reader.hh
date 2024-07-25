#pragma once

#include <istream>
#include <kakimasu/image/grayscale8_image.hh>
#include <kakimasu/image/rgb24_image.hh>
#include <memory>

namespace kakimasu::io
{
    class ImageReader
    {
    public:
        explicit ImageReader(std::istream& is);
        virtual ~ImageReader() = default;

        virtual std::unique_ptr<image::AbstractImage> read() = 0;

    protected:
        std::istream& is_;
    };
} // namespace kakimasu::io

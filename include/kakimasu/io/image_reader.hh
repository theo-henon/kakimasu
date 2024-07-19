#pragma once

#include <istream>
#include <kakimasu/image/rgb24_image.hh>
#include <kakimasu/image/grayscale8_image.hh>

namespace kakimasu::io
{
    class ImageReader
    {
    public:
        explicit ImageReader(std::istream& is);
        virtual ~ImageReader() = default;

        virtual image::Rgb24Image read_rgb24() = 0;
        virtual image::Grayscale8Image read_grayscale8() = 0;

    private:
        std::istream& is_;
    };
} // namespace kakimasu::io

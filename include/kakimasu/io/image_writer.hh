#pragma once

#include <kakimasu/image/bitmap_image.hh>
#include <kakimasu/image/grayscale8_image.hh>
#include <kakimasu/image/rgb24_image.hh>
#include <ostream>

namespace kakimasu::io
{
    class ImageWriter
    {
    public:
        explicit ImageWriter(std::ostream& os);
        virtual ~ImageWriter() = default;

        virtual void write(const image::Rgb24Image* img) = 0;
        virtual void write(const image::Grayscale8Image* img) = 0;
        virtual void write(const image::BitmapImage* img) = 0;
    protected:
        std::ostream& os_;
    };
} // namespace kakimasu::io
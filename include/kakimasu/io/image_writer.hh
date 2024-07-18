#pragma once

#include <kakimasu/image/image.hh>
#include <ostream>

namespace kakimasu::io
{
    template <typename ImageType>
    class ImageWriter
    {
    public:
        inline explicit ImageWriter(std::ostream& os);
        virtual ~ImageWriter() = default;

        virtual void write(const ImageType& img) = 0;

    protected:
        std::ostream& os_;
    };
} // namespace kakimasu::io

#include "image_writer.hxx"
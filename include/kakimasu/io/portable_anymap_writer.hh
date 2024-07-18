#pragma once

#include <kakimasu/image/rgb24_image.hh>

#include "image_writer.hh"

namespace kakimasu::io
{
    class PortableAnymapWriter : public ImageWriter<image::Rgb24Image>
    {
    public:
        explicit PortableAnymapWriter(std::ostream& os);

        void write(const image::Rgb24Image& img) override;
    };
} // namespace kakimasu::io

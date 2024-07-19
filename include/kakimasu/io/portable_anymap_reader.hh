#pragma once

#include "image_reader.hh"

namespace kakimasu::io
{
    class PortableAnymapReader : public ImageReader
    {
    public:
        explicit PortableAnymapReader(std::istream& is);

        image::Rgb24Image read_rgb24() override;
        image::Grayscale8Image read_grayscale8() override;
    };
} // namespace kakimasu::io

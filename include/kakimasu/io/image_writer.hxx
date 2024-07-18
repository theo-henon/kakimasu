#pragma once

#include "image_writer.hh"

namespace kakimasu::io
{
    template <typename ImageType>
    ImageWriter<ImageType>::ImageWriter(std::ostream& os)
        : os_(os)
    {}
} // namespace kakimasu::io
#include <kakimasu/io/image_reader.hh>

namespace kakimasu::io
{
    ImageReader::ImageReader(std::istream& is)
        : is_(is)
    {}
} // namespace kakimasu::io
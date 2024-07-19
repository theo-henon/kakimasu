#include <kakimasu/io/portable_anymap_reader.hh>

namespace kakimasu::io
{
    PortableAnymapReader::PortableAnymapReader(std::istream& is)
        : ImageReader(is)
    {}

    image::Rgb24Image PortableAnymapReader::read_rgb24()
    {
        return { 0, 0 };
    }

    image::Grayscale8Image PortableAnymapReader::read_grayscale8()
    {
        return { 0, 0 };
    }
} // namespace kakimasu::io
#include <kakimasu/io/image_writer.hh>

namespace kakimasu::io
{
    ImageWriter::ImageWriter(std::ostream& os)
        : os_(os)
    {}
} // namespace kakimasu::io
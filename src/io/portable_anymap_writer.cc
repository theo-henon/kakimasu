#include <kakimasu/io/portable_anymap_writer.hh>

namespace kakimasu::io
{
    PortableAnymapWriter::PortableAnymapWriter(std::ostream& os)
        : ImageWriter(os)
    {}

    void PortableAnymapWriter::write(const image::Rgb24Image& img)
    {
        os_ << "P3\n";

        os_ << img.get_width() << ' ' << img.get_height() << '\n';
        os_ << UINT8_MAX << '\n';

        for (uint32_t y = 0; y < img.get_height(); y++)
        {
            for (uint32_t x = 0; x < img.get_width(); x++)
            {
                image::Rgb24Color pixel = img.get_pixel(x, y);
                os_ << static_cast<int>(pixel.get_red()) << ' '
                    << static_cast<int>(pixel.get_green()) << ' '
                    << static_cast<int>(pixel.get_blue());

                if (x < img.get_width() - 1)
                    os_ << ' ';
            }
            os_ << '\n';
        }
    }
} // namespace kakimasu::io
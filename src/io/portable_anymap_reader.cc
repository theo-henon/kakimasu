#include <kakimasu/io/portable_anymap_reader.hh>
#include <sstream>

namespace kakimasu::io
{
    PortableAnymapReader::PortableAnymapReader(std::istream& is)
        : ImageReader(is)
        , width_(0)
        , height_(0)
        , color_depth_(0)
    {}

    std::unique_ptr<image::AbstractImage> PortableAnymapReader::read()
    {
        read_line();
        magic_number_ = line_;

        read_dimensions();

        if (magic_number_ == "P1")
            return read_bitmap();
        else if (magic_number_ == "P2")
        {
            read_color_depth();
            return read_grayscale8();
        }
        else if (magic_number_ == "P3")
        {
            read_color_depth();
            if (color_depth_ == 255)
                return read_rgb24();
            else
                throw std::runtime_error("Color depth not handled");
        }
        else
            throw std::runtime_error("Invalid magic number");
    }

    void PortableAnymapReader::read_line()
    {
        do
        {
            std::getline(is_, line_);
        } while (is_comment_line());
    }

    bool PortableAnymapReader::is_comment_line() const
    {
        return !line_.empty() && line_[0] == '#';
    }

    void PortableAnymapReader::read_dimensions()
    {
        read_line();
        std::stringstream ss(line_);
        ss >> width_ >> height_;
    }

    void PortableAnymapReader::read_color_depth()
    {
        read_line();
        color_depth_ = std::stol(line_);
    }

    std::unique_ptr<image::Rgb24Image> PortableAnymapReader::read_rgb24()
    {
        auto img = std::make_unique<image::Rgb24Image>(width_, height_);
        uint32_t row = 0;
        read_line();
        while (!is_.eof())
        {
            std::stringstream ss(line_);

            uint32_t col = 0;
            while (!ss.eof())
            {
                uint32_t r = 0;
                uint32_t g = 0;
                uint32_t b = 0;
                ss >> r >> g >> b;
                uint8_t r8 = r > 255 ? 255 : r;
                uint8_t g8 = g > 255 ? 255 : g;
                uint8_t b8 = b > 255 ? 255 : b;
                img->set_pixel(col, row, { r8, g8, b8 });
                col++;
            }
            row++;
            read_line();
        }
        return img;
    }

    std::unique_ptr<image::Grayscale8Image>
    PortableAnymapReader::read_grayscale8()
    {
        auto img = std::make_unique<image::Grayscale8Image>(width_, height_);
        uint32_t row = 0;
        read_line();
        while (!is_.eof())
        {
            std::stringstream ss(line_);

            uint32_t col = 0;
            while (!ss.eof())
            {
                uint32_t scale = 0;
                ss >> scale;
                uint8_t scale8 = scale > 255 ? 255 : scale;
                img->set_pixel(col, row, image::Grayscale8Color(scale8));
                col++;
            }
            row++;
            read_line();
        }
        return img;
    }

    std::unique_ptr<image::BitmapImage> PortableAnymapReader::read_bitmap()
    {
        auto img = std::make_unique<image::BitmapImage>(width_, height_);
        uint32_t row = 0;
        read_line();
        while (!is_.eof())
        {
            std::stringstream ss(line_);

            uint32_t col = 0;
            while (!ss.eof())
            {
                bool bit = false;
                ss >> bit;
                img->set_pixel(col, row, bit);
                col++;
            }
            row++;
            read_line();
        }
        return img;
    }
} // namespace kakimasu::io
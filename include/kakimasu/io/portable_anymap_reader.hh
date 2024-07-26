#pragma once

#include <kakimasu/image/bitmap_image.hh>

#include "image_reader.hh"

namespace kakimasu::io
{
    class PortableAnymapReader : public ImageReader
    {
    public:
        explicit PortableAnymapReader(std::istream& is);
        ~PortableAnymapReader() override = default;

        std::unique_ptr<image::AbstractImage> read() override;

    private:
        std::string line_;
        std::string magic_number_;
        uint32_t width_;
        uint32_t height_;
        uint32_t color_depth_;

        void read_line();
        [[nodiscard]] bool is_comment_line() const;
        void read_dimensions();
        void read_color_depth();
        std::unique_ptr<image::Rgb24Image> read_rgb24();
        std::unique_ptr<image::Grayscale8Image> read_grayscale8();
        std::unique_ptr<image::BitmapImage> read_bitmap();
    };
} // namespace kakimasu::io

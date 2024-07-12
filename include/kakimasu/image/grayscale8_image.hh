#include "pixmap_image.hh"

namespace kakimasu::image
{
    class Grayscale8Image : public PixmapImage<1, BitDepth::BITS_8>
    {
    public:
        Grayscale8Image(uint32_t width, uint32_t height);
        ~Grayscale8Image() override = default;

        [[nodiscard]] uint8_t get_scale(uint32_t x, uint32_t y) const;
        void set_scale(uint32_t x, uint32_t y, uint8_t scale);
    };
} // namespace kakimasu::image
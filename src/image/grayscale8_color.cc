#include <kakimasu/image/grayscale8_color.hh>
#include <stdexcept>

namespace kakimasu::image
{

    Grayscale8Color::Grayscale8Color()
        : scale_(0)
    {}

    Grayscale8Color::Grayscale8Color(uint8_t scale)
        : scale_(scale)
    {}

    int Grayscale8Color::get_num_channels() const
    {
        return 1;
    }

    uint8_t Grayscale8Color::get_channel(int index) const
    {
        if (index != 0)
            throw std::out_of_range("Channel index out of range");
        return scale_;
    }

    void Grayscale8Color::set_channel(int index, uint8_t value)
    {
        if (index != 0)
            throw std::out_of_range("Channel index out of range");
        scale_ = value;
    }

    uint8_t Grayscale8Color::get_scale() const
    {
        return scale_;
    }
    void Grayscale8Color::set_scale(uint8_t value)
    {
        scale_ = value;
    }
} // namespace kakimasu::image
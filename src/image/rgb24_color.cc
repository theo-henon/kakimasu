#include <kakimasu/image/rgb24_color.hh>
#include <stdexcept>

namespace kakimasu::image
{

    Rgb24Color::Rgb24Color()
        : red_(0)
        , green_(0)
        , blue_(0)
    {}

    Rgb24Color::Rgb24Color(uint8_t red, uint8_t green, uint8_t blue)
        : red_(red)
        , green_(green)
        , blue_(blue)
    {}

    int Rgb24Color::get_num_channels() const
    {
        return 3;
    }

    uint8_t Rgb24Color::get_channel(int index) const
    {
        switch (index)
        {
        case 0:
            return red_;
        case 1:
            return green_;
        case 2:
            return blue_;
        default:
            throw std::out_of_range("Channel index out of range");
        }
    }

    void Rgb24Color::set_channel(int index, uint8_t value)
    {
        switch (index)
        {
        case 0:
            red_ = value;
            break;
        case 1:
            green_ = value;
            break;
        case 2:
            blue_ = value;
            break;
        default:
            throw std::out_of_range("Channel index out of range");
        }
    }

    uint8_t Rgb24Color::get_red() const
    {
        return red_;
    }

    void Rgb24Color::set_red(uint8_t value)
    {
        red_ = value;
    }

    uint8_t Rgb24Color::get_green() const
    {
        return green_;
    }

    void Rgb24Color::set_green(uint8_t value)
    {
        green_ = value;
    }

    uint8_t Rgb24Color::get_blue() const
    {
        return blue_;
    }

    void Rgb24Color::set_blue(uint8_t value)
    {
        blue_ = value;
    }

    std::ostream& operator<<(std::ostream& os, const Rgb24Color& color)
    {
        return os << "(R: " << static_cast<int>(color.red_)
                  << ", G: " << static_cast<int>(color.green_)
                  << ", B: " << static_cast<int>(color.blue_) << ")";
    }
} // namespace kakimasu::image
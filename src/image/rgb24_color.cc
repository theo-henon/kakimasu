#include <kakimasu/image/rgb24_color.hh>

namespace kakimasu::image
{
    std::ostream& operator<<(std::ostream& os, Rgb24Color color)
    {
        return os << "(r: " << static_cast<int>(color.r)
                  << ", g: " << static_cast<int>(color.g)
                  << ", b: " << static_cast<int>(color.b) << ')';
    }
} // namespace kakimasu::image
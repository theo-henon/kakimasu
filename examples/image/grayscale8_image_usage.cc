#include <iostream>
#include <kakimasu/image/grayscale8_image.hh>

namespace kimg = kakimasu::image;

int main()
{
    // Initialize a new image of size 80x40 with 1 channel (gray scale) of 8
    // bits depth
    kimg::Grayscale8Image img(80, 40);

    // Get the gray scale of the upper left pixel and display it in stdout
    std::cout << "Gray scale of the upper left pixel: "
              << static_cast<int>(img.get_scale(0, 0)) << std::endl;

    // Set the gray scale of the upper left pixel and display it in stdout
    img.set_scale(0, 0, 57);
    std::cout << "Gray scale of the upper left pixel after modification: "
              << static_cast<int>(img.get_scale(0, 0)) << std::endl;

    return 0;
}
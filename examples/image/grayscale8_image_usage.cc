#include <iostream>
#include <kakimasu/image/grayscale8_image.hh>

namespace kimg = kakimasu::image;

int main()
{
    // Create a grayscale image of size 80x40 of 8 bits depth
    kimg::Grayscale8Image img(80, 40);

    // Get dimensions of the created image and display them in stdout
    std::cout << "Image dimensions: (" << img.get_width() << ", "
              << img.get_height() << ")\n";

    // Get the upper left pixel and display it on stdout
    kimg::Grayscale8Color pixel = img.get_pixel(0, 0);
    std::cout << "Upper left pixel gray scale: "
              << static_cast<int>(pixel.get_scale()) << std::endl;

    // Update the upper left pixel's scale to a random value and display it on
    // stdout
    img.set_pixel(0, 0, kimg::Grayscale8Color(67));
    pixel = img.get_pixel(0, 0);
    std::cout << "Upper left pixel color (after modification): "
              << static_cast<int>(pixel.get_scale()) << std::endl;

    return 0;
}
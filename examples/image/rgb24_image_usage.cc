#include <iostream>
#include <kakimasu/image/rgb24_image.hh>

namespace kimg = kakimasu::image;

int main()
{
    // Create an image of size 80x40, with 3 channels RGB, each of 8 bits
    kimg::Rgb24Image img(80, 40);

    // Get dimensions of the created image and display them in stdout
    std::cout << "Image dimensions: (" << img.get_width() << ", "
              << img.get_height() << ")\n";

    // Get the upper left pixel and display it on stdout
    kimg::Rgb24Color pixel = img.get_pixel(0, 0);
    std::cout << "Upper left pixel color: " << pixel << std::endl;

    // Update the upper left pixel's color to a random value and display it on
    // stdout
    img.set_pixel(0, 0, { 17, 131, 9 });
    pixel = img.get_pixel(0, 0);
    std::cout << "Upper left pixel color (after modification): " << pixel
              << std::endl;

    return 0;
}
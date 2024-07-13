#include <iostream>
#include <kakimasu/image/rgb24_image.hh>

namespace kimg = kakimasu::image;

int main()
{
    // Initialize a new image of size 80x40 with 3 channels RGB, each of 8 bits
    // depth
    kimg::Rgb24Image img(80, 40);

    // Get the upper left pixel color and display it in stdout
    kimg::Rgb24Color pcolor = img.get_color(0, 0);
    std::cout << "Upper left pixel color: " << pcolor << std::endl;

    // Set the upper left pixel color to a random color value and display it in
    // stdout
    img.set_color(0, 0, { 152, 1, 29 });
    pcolor = img.get_color(0, 0);
    std::cout << "Upper left pixel color after modification: " << pcolor
              << std::endl;

    // Modify the green color value of the upper left pixel and display it in
    // stdout
    img.set_green(0, 0, 42);
    pcolor = img.get_color(0, 0);
    std::cout << "Upper left pixel color after modification of the green color "
                 "value: "
              << pcolor << std::endl;

    // Display the green color value of the upper left pixel in stdout
    std::cout << "Green color value of the upper left pixel: "
              << static_cast<int>(img.get_green(0, 0)) << std::endl;
    return 0;
}
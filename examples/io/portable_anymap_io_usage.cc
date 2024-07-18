#include <fstream>
#include <iostream>
#include <kakimasu/io/portable_anymap_writer.hh>

namespace kimg = kakimasu::image;
namespace kio = kakimasu::io;

int main()
{
    // Create a writer for pixmap format to stdout
    kio::PortableAnymapWriter stdout_writer(std::cout);

    // Create another writer to a file named 'wikipedia.pnm'
    std::ofstream file("wikipedia.pnm");
    kio::PortableAnymapWriter file_writer(file);

    // Create an Rgb24Image like in the Wikipedia page for portable pixmap
    // format See: https://fr.wikipedia.org/wiki/Portable_pixmap
    kimg::Rgb24Image img(3, 2);
    img.set_pixel(0, 0, { 255, 0, 0 });
    img.set_pixel(1, 0, { 0, 255, 0 });
    img.set_pixel(2, 0, { 0, 0, 255 });
    img.set_pixel(0, 1, { 255, 255, 0 });
    img.set_pixel(1, 1, { 255, 255, 255 });

    // Write image in output streams
    stdout_writer.write(img);
    file_writer.write(img);
}
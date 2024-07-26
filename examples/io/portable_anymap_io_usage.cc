#include <fstream>
#include <iostream>
#include <kakimasu/io/portable_anymap_reader.hh>
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
    stdout_writer.write(&img);
    file_writer.write(&img);
    file.close();

    // Create a reader for previously written image and write it to stdout
    std::ifstream previous_file("wikipedia.pnm");
    kio::PortableAnymapReader reader(previous_file);
    auto img_read = reader.read();
    std::cout << "\nImage read:\n";
    stdout_writer.write(dynamic_cast<kimg::Rgb24Image*>(img_read.get()));

    // Create a little grayscale image
    kimg::Grayscale8Image gimg(2, 2);
    gimg.set_pixel(0, 0, kimg::Grayscale8Color(0));
    gimg.set_pixel(1, 0, kimg::Grayscale8Color(64));
    gimg.set_pixel(0, 1, kimg::Grayscale8Color(128));
    gimg.set_pixel(1, 1, kimg::Grayscale8Color(255));

    // Create a writer for grayscale format to a file named "gray.pnm"
    std::ofstream gofile("gray.pnm");
    kio::PortableAnymapWriter gfile_writer(gofile);
    gfile_writer.write(&gimg);
    gofile.close();

    // Create a reader for the previously written image
    std::ifstream gifile("gray.pnm");
    kio::PortableAnymapReader greader(gifile);
    auto gimg_read = greader.read();
    std::cout << "\nImage read:\n";
    stdout_writer.write(dynamic_cast<kimg::Grayscale8Image*>(gimg_read.get()));

    // Create a little bitmap image
    kimg::BitmapImage bimg(2, 2);
    bimg.set_pixel(0, 0, true);
    bimg.set_pixel(1, 0, false);
    bimg.set_pixel(0, 1, false);
    bimg.set_pixel(1, 1, true);

    // Create a writer for bitmap format to a file named "bitmap.pnm"
    std::ofstream bofile("bitmap.pnm");
    kio::PortableAnymapWriter bwriter(bofile);
    bwriter.write(dynamic_cast<kimg::BitmapImage*>(&bimg));
    bofile.close();

    // Create a reader for the previously written image
    std::ifstream bifile("bitmap.pnm");
    kio::PortableAnymapReader breader(bifile);
    auto bimg_read = breader.read();
    std::cout << "\nImage read:\n";
    stdout_writer.write(dynamic_cast<kimg::BitmapImage*>(bimg_read.get()));
}
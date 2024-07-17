#include <gtest/gtest.h>
#include <kakimasu/image/rgb24_image.hh>

namespace kimg = kakimasu::image;

TEST(rgb24_image, create_invalid_width)
{
    ASSERT_THROW(kimg::Rgb24Image(0, 40), std::invalid_argument);
}

TEST(rgb24_image, create_invalid_height)
{
    ASSERT_THROW(kimg::Rgb24Image(40, 0), std::invalid_argument);
}

TEST(rgb24_image, create_valid)
{
    kimg::Rgb24Image img(80, 40);
    ASSERT_EQ(img.get_width(), 80);
    ASSERT_EQ(img.get_height(), 40);

    for (uint32_t x = 0; x < img.get_width(); x++)
    {
        for (uint32_t y = 0; y < img.get_height(); y++)
        {
            kimg::Rgb24Color pixel = img.get_pixel(x, y);
            ASSERT_EQ(pixel.get_red(), 0);
            ASSERT_EQ(pixel.get_green(), 0);
            ASSERT_EQ(pixel.get_blue(), 0);
        }
    }
}

TEST(rgb24_image, get_pixel_out_of_range_width)
{
    kimg::Rgb24Image img(80, 40);
    ASSERT_EQ(img.get_width(), 80);
    ASSERT_EQ(img.get_height(), 40);
    ASSERT_THROW(kimg::Rgb24Color pixel = img.get_pixel(80, 2);
                 , std::out_of_range);
}

TEST(rgb24_image, get_pixel_out_of_range_height)
{
    kimg::Rgb24Image img(80, 40);
    ASSERT_EQ(img.get_width(), 80);
    ASSERT_EQ(img.get_height(), 40);
    ASSERT_THROW(kimg::Rgb24Color pixel = img.get_pixel(2, 40);
                 , std::out_of_range);
}

TEST(rgb24_image, set_pixel_out_of_range_width)
{
    kimg::Rgb24Image img(80, 40);
    ASSERT_EQ(img.get_width(), 80);
    ASSERT_EQ(img.get_height(), 40);
    ASSERT_THROW(img.set_pixel(80, 2, { 1, 2, 3 });, std::out_of_range);
}

TEST(rgb24_image, set_pixel_out_of_range_height)
{
    kimg::Rgb24Image img(80, 40);
    ASSERT_EQ(img.get_width(), 80);
    ASSERT_EQ(img.get_height(), 40);
    ASSERT_THROW(img.set_pixel(2, 40, { 1, 2, 3 });, std::out_of_range);
}

TEST(rgb24_image, update_upper_left_pixel)
{
    kimg::Rgb24Image img(80, 40);
    ASSERT_EQ(img.get_width(), 80);
    ASSERT_EQ(img.get_height(), 40);

    img.set_pixel(0, 0, { 57, 3, 203 });
    kimg::Rgb24Color pixel = img.get_pixel(0, 0);
    ASSERT_EQ(pixel.get_red(), 57);
    ASSERT_EQ(pixel.get_green(), 3);
    ASSERT_EQ(pixel.get_blue(), 203);
}
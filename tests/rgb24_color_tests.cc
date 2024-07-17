#include <gtest/gtest.h>
#include <kakimasu/image/rgb24_color.hh>

namespace kimg = kakimasu::image;

TEST(rgb24_color, create_no_arg)
{
    kimg::Rgb24Color color;
    ASSERT_EQ(color.get_num_channels(), 3);
    ASSERT_EQ(color.get_red(), 0);
    ASSERT_EQ(color.get_green(), 0);
    ASSERT_EQ(color.get_blue(), 0);
}

TEST(rgb24_color, create_with_args)
{
    kimg::Rgb24Color color(3, 20, 116);
    ASSERT_EQ(color.get_num_channels(), 3);
    ASSERT_EQ(color.get_red(), 3);
    ASSERT_EQ(color.get_green(), 20);
    ASSERT_EQ(color.get_blue(), 116);
}

TEST(rgb24_color, update_channels)
{
    kimg::Rgb24Color color;

    color.set_red(10);
    ASSERT_EQ(color.get_red(), 10);

    color.set_channel(0, 2);
    ASSERT_EQ(color.get_channel(0), 2);

    color.set_green(7);
    ASSERT_EQ(color.get_green(), 7);

    color.set_channel(1, 8);
    ASSERT_EQ(color.get_channel(1), 8);

    color.set_blue(173);
    ASSERT_EQ(color.get_blue(), 173);

    color.set_channel(2, 17);
    ASSERT_EQ(color.get_channel(2), 17);
}

TEST(rgb24_color, get_channel_in_range)
{
    kimg::Rgb24Color color(1, 2, 3);
    ASSERT_EQ(color.get_red(), color.get_channel(0));
    ASSERT_EQ(color.get_green(), color.get_channel(1));
    ASSERT_EQ(color.get_blue(), color.get_channel(2));
}

TEST(rgb24_color, get_channel_out_of_range)
{
    kimg::Rgb24Color color;
    ASSERT_THROW((void)color.get_channel(3), std::out_of_range);
}

TEST(rgb24_color, set_channel_out_of_range)
{
    kimg::Rgb24Color color;
    ASSERT_THROW(color.set_channel(3, 10), std::out_of_range);
}

TEST(rgb24_color, op_ostream)
{
    kimg::Rgb24Color color(1, 2, 3);
    testing::internal::CaptureStdout();
    std::cout << color << std::endl;
    std::string output = testing::internal::GetCapturedStdout();
    ASSERT_EQ(output, "(R: 1, G: 2, B: 3)\n");
}

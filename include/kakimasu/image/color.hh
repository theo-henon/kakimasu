#pragma once

#include <cstddef>

namespace kakimasu::image
{
    template <int NumChannels, typename ChannelType>
    class Color
    {
    public:
        virtual ~Color() = default;

        [[nodiscard]] virtual int get_num_channels() const = 0;
        virtual ChannelType get_channel(int index) const = 0;
        virtual void set_channel(int index, ChannelType value) = 0;
    };
} // namespace kakimasu::image

#pragma once

#include "version.hh"

namespace kakimasu
{
    inline uint get_version_major()
    {
        return KAKIMASU_VERSION_MAJOR;
    }

    inline uint get_version_minor()
    {
        return KAKIMASU_VERSION_MINOR;
    }

    inline uint get_version_patch()
    {
        return KAKIMASU_VERSION_PATCH;
    }

    inline std::string get_version_string()
    {
        return KAKIMASU_VERSION_STRING;
    }
} // namespace kakimasu
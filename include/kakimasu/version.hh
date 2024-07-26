#pragma once

#define KAKIMASU_VERSION_MAJOR 1
#define KAKIMASU_VERSION_MINOR 0
#define KAKIMASU_VERSION_PATCH 0
#define KAKIMASU_VERSION_STRING "1.0.0"

#include <string>

namespace kakimasu
{
    uint get_version_major();
    uint get_version_minor();
    uint get_version_patch();
    std::string get_version_string();
} // namespace kakimasu
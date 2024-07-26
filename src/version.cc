#include <kakimasu/version.hh>

namespace kakimasu
{
    uint get_version_major()
    {
        return KAKIMASU_VERSION_MAJOR;
    }

    uint get_version_minor()
    {
        return KAKIMASU_VERSION_MINOR;
    }

    uint get_version_patch()
    {
        return KAKIMASU_VERSION_PATCH;
    }

    std::string get_version_string()
    {
        return KAKIMASU_VERSION_STRING;
    }
} // namespace kakimasu
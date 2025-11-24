#ifndef HELPERS_H
#define HELPERS_H

#include <string>
#include <filesystem>

inline bool fileExists(const std::string& path) {
    return std::filesystem::exists(path);
}

#endif

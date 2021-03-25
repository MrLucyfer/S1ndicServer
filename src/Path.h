#pragma once
#include <string>

class Path {
public:
    Path();
    ~Path();

    char* Open(const std::string& rel_path);

private:
    bool IsDirectory(const std::string& rel_path);

private:
    std::string m_rootPath;
};

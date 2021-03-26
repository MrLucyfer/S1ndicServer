#pragma once
#include <string>

class Path {
public:
    static Path& Get();
    char* Open(const std::string& rel_path, int& length);
private:
    Path();
    ~Path();
    bool IsDirectory(const std::string& rel_path);

private:
    std::string m_rootPath;
};

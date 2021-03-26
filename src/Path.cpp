#include "Path.h"
#include "Logger.cpp"
#include <filesystem>
#include <fstream>
#include <vector>

Path::Path() {
    std::filesystem::path temp = std::filesystem::current_path();
    m_rootPath = temp.string();
    m_rootPath += "/public_html";
}

Path::~Path() {

}

char* Path::Open(const string& rel_path, int& length) {
    if(IsDirectory(rel_path)) {
        return nullptr;
    } else {
        std::fstream file(rel_path);
        std::ifstream::pos_type pos = file.tellg();
        std::vector<char> bytes(pos);

        file.seekg(0, ios::beg);
        file.read(&bytes[0], pos);

        length = bytes.size();

        return bytes.data();
    }
}

bool Path::IsDirectory(const string& rel_path) {
    std::filesystem::path temp_path(rel_path);
    return std::filesystem::is_directory(temp_path);
}

Path& Path::Get() {
    static Path path;
    return path;
}


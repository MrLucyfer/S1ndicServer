#include "Path.h"
#include "Logger.cpp"
#include <filesystem>

Path::Path() {
    std::filesystem::path temp = std::filesystem::current_path();
    m_rootPath = temp.string();
    m_rootPath += "/public_html";
    Logger::PrintMessage(m_rootPath);
}

Path::~Path() {

}
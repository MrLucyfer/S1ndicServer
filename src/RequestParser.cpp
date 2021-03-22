#include "RequestParser.h"
#include "Logger.cpp"

RequestParser::RequestParser(const std::string& rawData) {
    m_rawData = rawData;
}

RequestParser::~RequestParser() {

}

PetitionData RequestParser::Parse() {
    std::string delimiter = "\r\n";

    unsigned int pos = 0;
    std::string token;
    
    while((pos = m_rawData.find(delimiter) != std::string::npos)) {
        token = m_rawData.substr(0, pos);
        Logger::PrintMessage(token);
        m_rawData.erase(0, pos + delimiter.length());
    }
    return m_petition;
}   
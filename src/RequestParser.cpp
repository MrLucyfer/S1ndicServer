#include "RequestParser.h"
#include "Logger.cpp"

RequestParser::RequestParser(const std::string& rawData) {
    m_rawData = rawData;
}

RequestParser::~RequestParser() {

}

PetitionData RequestParser::Parse() {
    Phases currentPhase = Phases::Method;
    std::string currentLine = NextLine();
    unsigned int delimIndex;
    std::string item;
    while(currentLine != "\0") {
        //Logger::PrintMessage(currentLine);
        switch(currentPhase) {
            case Phases::Method:
                delimIndex = currentLine.find(" ");
                item = currentLine.substr(0, delimIndex);
                m_petition.setMethod(item);
                currentLine.erase(0, delimIndex + 1);
                currentPhase = Phases::Path;
                break;
            case Phases::Path:
                delimIndex = currentLine.find(" ");
                item = currentLine.substr(0, delimIndex);
                m_petition.setPath(item);
                currentLine.erase(0, delimIndex + 1);
                currentPhase = Phases::Protocol;
                break;
            case Phases::Protocol:
                delimIndex = currentLine.find(" ");
                item = currentLine.substr(0, delimIndex);
                m_petition.setProtocol(item);
                currentLine.erase(0, delimIndex + 1);
                currentPhase = Phases::Header;
                currentLine = NextLine();
                break;
            case Phases::Header:
                std::string delimiter = ":";
                unsigned int index = currentLine.find(delimiter);
                std::string headerName = currentLine.substr(0, index);
                std::string headerValue = currentLine.substr(index+2, currentLine.length());
                m_petition.setHeader(headerName, headerValue);
                currentLine = NextLine();
                break;
        }
    }

    return m_petition;
}

std::string RequestParser::NextLine() {
    std::string delimiter = "\r\n";
    std::string current = "\0";
    unsigned int position = m_rawData.find(delimiter);
    if(position != std::string::npos) {
        current = m_rawData.substr(0, position);
        m_rawData.erase(0, position + delimiter.length());
    }

    return current;
}


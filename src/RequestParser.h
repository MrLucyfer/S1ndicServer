#pragma once
#include <string>
#include "PetitionData.h"

class RequestParser {
public:
    RequestParser(const std::string& rawData);
    ~RequestParser();

    PetitionData Parse();
private:
    enum Phases {
        Method,
        Path,
        Protocol,
        Header,
    };

    std::string NextLine();
    //void AppendHeader(const std::string& line);
    
private:
    std::string m_rawData;
    PetitionData m_petition;
};
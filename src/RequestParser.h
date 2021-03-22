#include <string>
#include "PetitionData.h"

class RequestParser {
public:
    RequestParser(const std::string& rawData);
    ~RequestParser();

    PetitionData Parse();
private:
    
private:
    std::string m_rawData;
    PetitionData m_petition;
};
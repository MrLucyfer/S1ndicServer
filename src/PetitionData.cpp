#include "PetitionData.h"

PetitionData::PetitionData() {

}


PetitionData::~PetitionData() {
    
}

void PetitionData::setMethod(const std::string& method) {
    m_sMethod = method;
    if(method == "GET") {
        m_method = Method::GET;
    } else if(method == "POST") {
        m_method = Method::POST;
    } else if(method == "PUT") {
        m_method = Method::PUT;
    } else {
        m_method = Method::ERR;
    }
}

void PetitionData::setsMethod(Method method) {
    if(method == Method::GET) {
        m_sMethod = "GET";
    } else if(method == Method::POST) {
        m_sMethod = "POST";
    } else if(method == Method::PUT) {
        m_sMethod = "PUT";
    } else {
        m_sMethod = "GET";
    }
}

void PetitionData::setPath(const std::string& path) {
    m_path = path;
}

void PetitionData::setProtocol(const std::string& protocol) {
    m_protocol = protocol;
}

void PetitionData::setHeader(std::string name, std::string value) {
    m_headers.insert(std::pair<std::string, std::string>(name, value));
}

void PetitionData::setBody(const std::string& body) {
    m_body = body;
}

std::string PetitionData::getMethod() const {
    return m_sMethod;
}

std::string PetitionData::getPath() const {
    return m_path;
}

std::map<std::string, std::string> PetitionData::getHeader() const {
    return m_headers;
}


#pragma once
#include <unordered_map>
#include <string>

class PetitionData{
public:
    PetitionData();
    ~PetitionData();

    enum Method {
        GET,
        POST,
        PUT,
    };

    void setMethod(Method method);
    void setPath(const std::string& path);
    void setProtocol(const std::string& protocol);
    void setHeaders(const std::unordered_map<std::string,std::string>& headers);
    void setBody(const std::string& body);

private:
    Method m_method;
    std::string m_path;
    std::string m_protocol;
    std::unordered_map<std::string, std::string> m_headers; // TODO replace this with your own
    std::string m_body;
};
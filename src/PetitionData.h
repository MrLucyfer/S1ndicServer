#pragma once
#include <map>
#include <string>

class PetitionData{
public:
    PetitionData();
    ~PetitionData();

    enum Method {
        GET,
        POST,
        PUT,
        ERR,
    };

    void setMethod(const std::string& method);
    void setsMethod(Method method);
    void setPath(const std::string& path);
    void setProtocol(const std::string& protocol);
    void setHeader(std::string name, std::string value);
    void setBody(const std::string& body);

    std::string getMethod() const;
    std::string getPath() const;
    std::string getProtocol() const;
    std::map<std::string, std::string> getHeader() const;
    std::string getBody() const;

private:
    Method m_method;
    std::string m_sMethod;
    std::string m_path;
    std::string m_protocol;
    std::map<std::string, std::string> m_headers; // TODO replace this with your own
    std::string m_body;
};
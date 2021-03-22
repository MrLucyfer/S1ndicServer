#pragma once
#include "DataBuffer.h"
#include "Logger.cpp"
#include <netinet/in.h>
#include <netinet/ip.h> 

class Petition {
public:
    Petition();
    Petition(const int& ip, const int& port);
    Petition(const int& ip, const int& port, char* bufferData, const int& dataLength);
    Petition(const int& ip, const int& port, DataBuffer* bufferData);
    Petition(const struct sockaddr_in& sender, DataBuffer* data);
    ~Petition();

    unsigned int getIp() const;
    int getPort() const;
    DataBuffer* getData() const;

    std::string getBufferString();

private:
    unsigned int m_ip;
    char* m_ipString;
    int m_port;
    DataBuffer* m_buffer;
};
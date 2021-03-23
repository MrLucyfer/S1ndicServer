#pragma once
#include <netinet/in.h>
#include <netinet/ip.h>
#include <iostream>
#include <functional>
#include "Petition.h"

class Socket {
public:
    Socket(int port);
    ~Socket();

    void Bind();
    void Listen(const std::function<void(Petition*, const int&)>& func);
    void Send(Petition* response, const int& descriptor);

private:
    Petition* Accept(int& fd);

private:
    int m_port;
    int m_socketFd;

    struct sockaddr_in m_socketInfo;
    struct in_addr m_address;
};
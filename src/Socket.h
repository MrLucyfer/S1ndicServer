#include <netinet/in.h>
#include <netinet/ip.h> 

class Socket {
public:
    Socket(int port);
    ~Socket();

    void Bind();
    void Listen();

private:
    void Accept();

private:
    int m_port;
    int m_socketFd;

    struct sockaddr_in m_socketInfo;
    struct in_addr m_address;
};
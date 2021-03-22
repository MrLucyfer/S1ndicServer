#include "Socket.h"

class Server {
public:
    Server(int port = 8080);
    ~Server();

    void listen();

private:
    int m_port;
    Socket* m_socket;
};
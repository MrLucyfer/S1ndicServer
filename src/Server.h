#include "Socket.h"
#include "Petition.h"

class Server {
public:
    Server(int port = 8080);
    ~Server();

    void listen();

    void OnRequest(Petition* req);

private:
    int m_port;
    Socket* m_socket;
};
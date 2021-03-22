#include "Server.h"

Server::Server(int port) {
    m_port = port;
    m_socket = new Socket(m_port);
    m_socket->Bind();
}

Server::~Server() {

}

void Server::listen() {
    m_socket->Listen();
}
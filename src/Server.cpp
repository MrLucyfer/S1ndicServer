#include "Server.h"
#include "Logger.cpp"
#include "RequestParser.h"
#include "PetitionData.h"
#include <string>

Server::Server(int port) {
    m_port = port;
    m_socket = new Socket(m_port);
    m_socket->Bind();
}

Server::~Server() {

}

void Server::listen() {

    auto OnRequest = [](Petition* req) {
        req->PrintPetition();
    };  

    // TODO make port number dynamic
    Logger::PrintMessage("Server listening on port -> 8080");
    for(;;) {
        m_socket->Listen(OnRequest);
    }
}

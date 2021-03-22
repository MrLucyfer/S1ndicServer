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
        std::string data = req->getBufferString();
        Logger::PrintMessage(data);
        RequestParser parser(data);
        PetitionData parsedRequest = parser.Parse();
    };  

    // TODO make port number dynamic
    Logger::PrintMessage("Server listening on port -> 8080");
    for(;;) {
        m_socket->Listen(OnRequest);
    }
}

void Server::OnRequest(Petition* request) {
    Logger::PrintMessage("Callback Trigered");
}
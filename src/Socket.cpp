#include <sys/socket.h>
#include <sys/types.h>
#include "Socket.h"
#include "Logger.cpp"
#include "Petition.h"

#define MAX_CONNECTIONS 3

Socket::Socket(int port) {
    m_port = port;

    m_socketFd = socket(AF_INET, SOCK_STREAM, 0);
    if(m_socketFd == -1) {
        Logger::PrintError("There has been an error while socket init.\n");
    }
}

Socket::~Socket() {

}

void Socket::Bind() {
    //Supply all info to the structures;
    m_address.s_addr = INADDR_ANY;

    m_socketInfo.sin_family = AF_INET;
    m_socketInfo.sin_port = htons(m_port); //Converting port number
    m_socketInfo.sin_addr = m_address;

    unsigned int length = sizeof(m_socketInfo);

    //The :: is to not confuse with std::bind https://stackoverflow.com/questions/10035294/compiling-code-that-uses-socket-function-bind-with-libcxx-fails
    int status = ::bind(m_socketFd, (struct sockaddr*) &m_socketInfo, length);

    if(status == -1) {
        Logger::PrintError("Error while binding the socket.\n");
    }
}

void Socket::Listen(void(*func)(Petition*)) {
    int status = listen(m_socketFd, MAX_CONNECTIONS);

    if(status == -1) {
        Logger::PrintError("Error while listening.\n");
    } else {
        Petition* request = Accept();
        if(request == nullptr) {
            Logger::PrintMessage("Something went wrong... Revise");
        } else {
            func(request);
        }
    }
}

Petition* Socket::Accept() {
    struct sockaddr_in incoming;
    unsigned int length = sizeof(incoming);
    int fd = accept(m_socketFd, (struct sockaddr*) &incoming, &length);
    if(fd == -1) {
        Logger::PrintError("Error accepting the request.\n");
    } else {
        Logger::PrintAddress(incoming);
        DataBuffer* buffer = new DataBuffer();
        int size = recv(fd, buffer->GetData(), buffer->GetSize(), 0);

        Petition* request = new Petition(ntohl(incoming.sin_addr.s_addr), ntohs(incoming.sin_port), buffer);
        return request;
    }    

    return nullptr;
}
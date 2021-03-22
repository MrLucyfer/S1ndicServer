#pragma once
#include <iostream>
#include <stdio.h>
#include <netinet/in.h>
#include <netinet/ip.h> 
#include <arpa/inet.h>
using namespace std;

namespace Logger {
    //TODO add some personalization to the messages.
    inline void PrintMessage(const string& message) {
        cout << message << endl;
    }

    inline void PrintError(const string& message) {
        cout << message << endl;
        perror(message.c_str());
    }

    inline void PrintAddress(const struct sockaddr_in& incoming) {
        int port = ntohs(incoming.sin_port);
        string address = inet_ntoa(incoming.sin_addr);

        cout << "Incoming connection from " << address << ":" << port << endl;
    }

}
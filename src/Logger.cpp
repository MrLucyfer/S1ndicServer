#include <iostream>
#include <stdio.h>
#include <netinet/in.h>
#include <netinet/ip.h> 

using namespace std;

inline string itoip(const int& address) {
        unsigned char bytes[4];
        bytes[0] = address & 0xFF;
        bytes[1] = (address >> 8) & 0xFF;
        bytes[2] = (address >> 16) & 0xFF;
        bytes[3] = (address >> 24) & 0xFF;

        string newAddress = "";

        for(int i = 0; i < 3; i++) {
            newAddress += bytes[i];
            newAddress += ".";
        }

        newAddress += bytes[2];

        return newAddress;
    }

namespace Logger {
    //TODO add some personalization to the messages.
    inline void PrintMessage(const string& message) {
        cout << message << endl;
    }

    inline void PrintError(const string& message) {
        cout << message << endl;
        perror(message.c_str());
    }

    inline void PrintAddres(const struct sockaddr_in& incoming) {
        int port = ntohs(incoming.sin_port);
        string address = itoip(ntohl(incoming.sin_addr.s_addr));

        cout << "Incoming connection from " << address << ":" << port << endl;
    }

}
#include "Petition.h"
#include "Path.h"
#include <fstream>
#include <iostream>

Petition::Petition() {
    m_buffer = nullptr;
}

Petition::Petition(const int& ip, const int& port, const std::string& path) {
    m_ip = ip;
    m_port = port;
    m_buffer = nullptr;
    m_data.setPath(path);
}

Petition::Petition(const int& ip, const int& port, char* data, const int& dataLength) {
    m_ip = ip;
    m_port = port;
    m_buffer = new DataBuffer(data, dataLength);
}

Petition::Petition(const int& ip, const int& port, DataBuffer* data) {
    m_ip = ip;
    m_port = port;
    m_buffer = data;
}

unsigned int Petition::getIp() const {
    return m_ip;
}

int Petition::getPort() const {
    return m_port;
}

DataBuffer* Petition::getData() const{
    return m_buffer;
}

std::string Petition::getBufferString() {
    if(m_buffer->GetStringSize() == 0) {
        m_buffer->MakeString();
    }
    return m_buffer->GetString();
}

void Petition::setData() {
    RequestParser parser(getBufferString());
    m_data = parser.Parse();
}

void Petition::PrintPetition() {
    std::string msg = "";
    msg += m_data.getMethod();
    msg += " ";
    msg += m_data.getPath();
    Logger::PrintMessage(msg);

}

void Petition::Deserialize() {
    setData();
}

std::string Petition::Serialize() {
    //std::string line;
    //std::ifstream file("public_html/index.html");//std::string body;

    auto path = m_data.getPath();
    Logger::PrintMessage(path);

    if(path == "/") {
        path = "/index.html";
    }

    //Return a struct
    int length;
    char* body = Path::Get().Open(path, length);


    std::string response = "";
    if(body != nullptr) {
        response += "HTTP/1.1 200 OK\r\n";
    } else {
        response += "HTTP/1.1 404 OK\r\n";
    }
    response += "Server: SindicServer\r\n";
    response += "Content-Length: ";
    response += std::to_string(length);
    response += "\r\n";
    response += "Connection: Close\r\n";
    response += "\r\n";
    if(body != nullptr) {
        response += body;
    }
    //Logger::PrintMessage(response);
    return response;
    m_buffer->SetData(response.data(), response.length());
}

std::string Petition::getPath() {
    return m_data.getPath();
}



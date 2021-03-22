#include "Petition.h"

Petition::Petition() {
    m_buffer = nullptr;
}

Petition::Petition(const int& ip, const int& port) {
    m_ip = ip;
    m_port = port;
    m_buffer = nullptr;
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

// Petition::Petition(const struct sockaddr_in& sender, DataBuffer* data) {
//     m_ipString = inet_ntoa(sender.sin_addr);
//     m_ip = ntohl(sender.sin_addr.s_addr);
//     m_po
// }

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

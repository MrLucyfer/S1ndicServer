#include "DataBuffer.h"

DataBuffer::DataBuffer() {
    m_size = 1024;
    m_buffer.resize(m_size);
}

DataBuffer::DataBuffer(char* data, int length) {
    m_buffer = std::vector<char>(data, data + length);
    m_size = length;
}


DataBuffer::~DataBuffer() {

}

void DataBuffer::SetSize(const int& size) {
    m_size = size;
}

char* DataBuffer::GetData() {
    return m_buffer.data();
}

void DataBuffer::SetData(const char* data, int length) {
    m_buffer = std::vector<char>(data, data + length);
    m_size = length;
}

const char* DataBuffer::GetData(unsigned int& length) {
    length = m_bufferString.size();
    return m_bufferString.data();
}

int DataBuffer::GetSize() {
    return m_buffer.size();
}

std::string DataBuffer::GetString() {
    return m_bufferString;
}

void DataBuffer::MakeString() {
    m_bufferString = std::string(m_buffer.data());
}

int DataBuffer::GetStringSize() {
    return m_bufferString.size();
}


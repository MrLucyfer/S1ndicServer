#include "DataBuffer.h"

DataBuffer::DataBuffer() {
    m_size = 1024;
    m_buffer.resize(m_size);
}

DataBuffer::~DataBuffer() {

}

void DataBuffer::SetSize(const int& size) {
    m_size = size;
}

char* DataBuffer::GetData() {
    return m_buffer.data();
}

int DataBuffer::GetSize() {
    return m_buffer.size();
}

std::string DataBuffer::GetString() {
    return m_bufferString;
}

void DataBuffer::MakeString() {
    m_bufferString = std::string(GetData());
}
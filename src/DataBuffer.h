#include <vector>
#include <string>

class DataBuffer {
public:
    DataBuffer();
    DataBuffer(char* data, int length);
    ~DataBuffer();

    void SetSize(const int& data);
    void SetData(const char* data, int length);

    char* GetData();
    const char* GetData(unsigned int& length);
    int GetSize();
    std::string GetString();

    int GetStringSize();

    void MakeString();

private:
    int m_size;
    std::vector<char> m_buffer; 
    std::string m_bufferString;
};
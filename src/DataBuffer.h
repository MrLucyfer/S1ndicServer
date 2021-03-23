#include <vector>
#include <string>

class DataBuffer {
public:
    DataBuffer();
    DataBuffer(char* data, int length);
    ~DataBuffer();

    void SetSize(const int& data);
    void SetString(const std::string& body);

    char* GetData();
    int GetSize();
    std::string GetString();

    int GetStringSize();

    void MakeString();

private:
    int m_size;
    std::vector<char> m_buffer; 
    std::string m_bufferString;
};
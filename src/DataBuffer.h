#include <vector>
#include <string>

class DataBuffer {
public:
    DataBuffer();
    ~DataBuffer();

    void SetSize(const int& data);

    char* GetData();
    int GetSize();
    std::string GetString();

    void MakeString();

private:
    int m_size;
    std::vector<char> m_buffer; 
    std::string m_bufferString;
};
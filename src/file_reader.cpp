#include "file_reader.h"
#include "exceptions.h"
using namespace std;

FileReader::FileReader(const char *filename)
{
    open(filename);
}

void FileReader::open(const char* filename)
{
    file = fopen(filename, "r");
    if (!file)
        throw FileOpenException("open");
}
void FileReader::close()
{
    fclose(file);
    file = nullptr;
}

int FileReader::readInt(bool &eof)
{
    int num;
    if (fscanf(file, "%i", &num) != 1)
        eof = true;
    else
        eof = false;
    return num;
}

float FileReader::readFloat(bool &eof)
{
    float num;
    if (fscanf(file, "%f", &num) != 1)
        eof = true;
    else
        eof = false;
    return num;
}

char FileReader::readChar(bool &eof)
{
    char ch;
    if (fscanf(file, "%c", &ch) != 1)
        eof = true;
    else
        eof = false;
    return ch;
}

FileReader::~FileReader()
{
    if (file)
        close();
}

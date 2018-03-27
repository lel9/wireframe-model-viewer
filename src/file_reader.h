#ifndef FILEREADER_H
#define FILEREADER_H

#include "base_file_reader.h"

#include <stdio.h>

class FileReader : public BaseFileReader
{
protected:
    FILE *file;

public:
    FileReader(const char *filename);
    ~FileReader();

    virtual int readInt(bool &f) override;
    virtual float readFloat(bool &f) override;
    virtual char readChar(bool &f) override;

protected:
    void open(const char *filename);
    void close();
};

#endif // FILEREADER_H

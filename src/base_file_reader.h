#ifndef _BASEFILEREADER_H
#define _BASEFILEREADER_H

class BaseFileReader
{
public:
    virtual ~BaseFileReader() { }

    virtual int readInt(bool &eof) = 0;
    virtual float readFloat(bool &eof) = 0;
    virtual char readChar(bool &eof) = 0;
};

#endif // _BASEFILEREADER_H

#ifndef MYEXEPTIONS_H
#define MYEXEPTIONS_H


#include <exception>
#include <string>

class AppException : public std::exception
{
public:
    AppException(){}
    virtual ~AppException(){}
    virtual const char *what() const throw() override
    {
        return "App exception\n";
    }
};


class ReaderException : public AppException
{
public:
    ReaderException(const char *str = "") :
        mess("ReaderExepction: ")
    {
        mess += str;
        mess += "\n";
    }
    virtual ~ReaderException(){}
    virtual const char *what() const throw() override
    {
        return mess.c_str();
    }
private:
    std::string mess;
};

class FileOpenException : public AppException
{
public:
    FileOpenException(const char *str = "") :
        mess("FileOpenException: ")
    {
        mess += str;
        mess += "\n";
    }
    virtual ~FileOpenException(){}
    virtual const char *what() const throw() override
    {
        return mess.c_str();
    }
private:
    std::string mess;
};

class NoSceneException : public AppException
{
public:
    NoSceneException(const char *str = "") :
        mess("NoSceneException: ")
    {
        mess += str;
        mess += "\n";
    }
    virtual ~NoSceneException(){}
    virtual const char *what() const throw() override
    {
        return mess.c_str();
    }
private:
    std::string mess;
};

class NoObjectException : public AppException
{
public:
    NoObjectException(const char *str = "") :
        mess("NoObjectException: ")
    {
        mess += str;
        mess += "\n";
    }
    virtual ~NoObjectException(){}
    virtual const char *what() const throw() override
    {
        return mess.c_str();
    }
private:
    std::string mess;
};

class DrawException : public AppException
{
public:
    DrawException(const char *str = "") :
        mess("DrawException: ")
    {
        mess += str;
        mess += "\n";
    }
    virtual ~DrawException(){}
    virtual const char *what() const throw() override
    {
        return mess.c_str();
    }
private:
    std::string mess;
};

#endif // MYEXEPTIONS_H

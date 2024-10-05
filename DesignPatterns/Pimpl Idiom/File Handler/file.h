#ifndef FILE_H
#define FILE_H
#include <iostream>
class FileHandler {
    public:
    FileHandler();
    ~FileHandler();
    FileHandler(const FileHandler&) = delete;
    FileHandler& operator=(const FileHandler&) = delete;

    // Public facing APIs
    bool open(const char* filename, const char* mode);
    void close();
    size_t read(char* buffer, size_t size);
    size_t write(const char* buffer, size_t size);

    private:
    class FileImpl;
    FileImpl *fileImpl;
};
#endif
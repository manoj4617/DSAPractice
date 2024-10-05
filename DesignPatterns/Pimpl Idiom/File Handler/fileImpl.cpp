#include "file.h"
#include <cstddef>
#include <cstdio>
#include <stdio.h>

class FileHandler::FileImpl{
    public:
    FILE *file = NULL;

    bool open(const char* fileName, const char* mode){
        file = fopen(fileName, mode);
        return file != NULL;
    }

    void close(){
        if(file){
            fclose(file);
            file = NULL;
        }
    }

    size_t read(char* buffer, size_t size){
        if(!file)
            return 0;
        return fread(buffer, sizeof(char),size, file);
    }
    size_t write(const char* buffer, size_t size){
        if(!file)
            return 0;
        return fwrite(buffer, sizeof(char),size, file);
    }
};

FileHandler::FileHandler() : fileImpl(new FileImpl()){ }

FileHandler::~FileHandler(){
    fileImpl->close();
    delete fileImpl;
}

bool FileHandler::open(const char* fileName, const char* mode){
    return fileImpl->open(fileName, mode);
}

void FileHandler::close(){
    fileImpl->close();
}

size_t FileHandler::read(char* buffer, size_t size){
    return fileImpl->read(buffer, size);
}

size_t FileHandler::write(const char* buffer, size_t size){
    return fileImpl->write(buffer, size);
}
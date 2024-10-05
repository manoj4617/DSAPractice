#include "file.h"
#include <iostream>
#include <string.h>
using namespace std;

int main(){
    FileHandler fileHandler;

    const char* fileName = "test.txt";
    if(!fileHandler.open(fileName, "w")){
        cerr << "Failed to open file for writing\n";
        return 1;
    }

    const char* data = "Hello, world";
    fileHandler.write(data, strlen(data));
    fileHandler.close();

    if(!fileHandler.open(fileName, "r+")){
        cerr << "Failed to open file\n";
        return 1;
    }

    char buffer[256];
    size_t bytesRead = fileHandler.read(buffer, sizeof(buffer) - 1);
    buffer[bytesRead] = '\0';
    cout << "File contents: " << buffer << " \n";

    fileHandler.close();
}
#include <iostream>
#include <vector>
#include <memory>

using namespace std;

class FileSystem {
    public:
    ~FileSystem() = default;
    virtual void ls(int indent = 0) = 0;
};

class File : public FileSystem {
    private:
    string fileName;

    public:
    File(const string& _fileName) : fileName(_fileName){}

    void ls(int indent = 0) override {
        cout << string(indent, ' ') << "- File: " << fileName << "\n";
    }
};

class Directory : public FileSystem {
    private:
    string dirName;
    vector<unique_ptr<FileSystem>> fileOrDirList;

    public:
    Directory(string _dirName) : dirName(_dirName){}
    void add(unique_ptr<FileSystem> fileSystem){
        fileOrDirList.push_back(move(fileSystem));
    }
    void ls(int indent = 0) override {
        cout << string(indent, ' ') <<"+ Directory name: " << dirName << "\n";
        for(auto& filesys : fileOrDirList){
            filesys->ls(indent + 2);
        }
    }
};

int main(){
    // Create root directory
    auto root = make_unique<Directory>("home");
    
    // Add files and subdirectories to root
    root->add(make_unique<File>("text.txt"));
    auto codebaseDir = make_unique<Directory>("Codebase");
    codebaseDir->add(make_unique<File>("main.cpp"));
    codebaseDir->add(make_unique<File>("utils.h"));
    root->add(move(codebaseDir));
    root->add(make_unique<File>("text2.txt"));
    
    // Display filesystem structure
    root->ls();

    return 0;
}

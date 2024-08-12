#include <iostream>

class IStorage {
    public:
    virtual void save(const std::string& data) = 0;
};

class FileManager {
private:
    IStorage& storage; // IStorage is an abstraction

public:
    FileManager(IStorage& stor) : storage(stor) {}

    void saveFile(const std::string& data) {
        storage.save(data);
    }
};

class LocalStorage : public IStorage {
public:
    void save(const std::string& data) override {
        std::cout << "Saving to local storage: " << data << std::endl;
    }
};

class CloudStorage : public IStorage {
public:
    void save(const std::string& data) override {
        std::cout << "Saving to cloud storage: " << data << std::endl;
    }
};

int main() {
    CloudStorage cloud;
    FileManager manager(cloud); // Injecting dependency
    manager.saveFile("Sample data");
    return 0;
}
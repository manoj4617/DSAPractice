#include <iostream>

using namespace std;

class IStorage {
    public:
    virtual void save(const string& data) = 0;
    virtual void load(const string& data) = 0;
};

class FileManager {
    private:
    IStorage& storage;

    public:
    FileManager(IStorage& stor) : storage(stor){}

    /**
     * This function takes a string of data and saves it to the storage that was
     * passed into the constructor of this FileManager. This is where the dependency
     * inversion comes in - the FileManager doesn't know or care what kind of storage
     * it's using, whether it's a local file, a database, or a web service. It just
     * knows that it needs to save the data, and it lets the storage object handle
     * the details of how to do that.
     *
     * @param data The string of data to be saved.
     */
    void saveData(const string& data){
        storage.save(data); // Call the save function on the storage object.
    }
};

class CloudStorage : public IStorage {
    public:
    void save(const string& data) override{
        cout << "Storing in cloud storage: " << data << endl;
    }

    void load(const string& data) override {
        cout << "Loading from cloud storage: " << data << endl;
    }
};

class LocalStorage : public IStorage {
    public:
    void save(const string& data) override{
        cout << "Storing in local storage: " << data << endl;
    }

    void load(const string& data) override {
        cout << "Loading from local storage: " << data << endl;
    }
};

int main(){
    CloudStorage cloud;
    LocalStorage local;

    FileManager manager(local);
    manager.saveData("some local data");

    FileManager manager1(cloud);
    manager1.saveData("some cloud data");
    return 0;
}
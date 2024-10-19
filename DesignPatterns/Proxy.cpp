#include <iostream>

class Image {
    public:
    virtual void display() = 0;
    virtual ~Image() = default;
};

class RealImage : public Image {
    private:
    std::string fileName;

    public:
    RealImage(const std::string filename) : fileName(filename) {
        loadFromDisk();
    }

    void loadFromDisk(){
        std::cout << "Loading from file: " << fileName << "\n";
    }

    void display() override {
        std::cout << "Displaying from file: " << fileName << "\n";
    }
};

/**
 * The Proxy design pattern provides a surrogate or placeholder for another object to control access to it.
 * It is used to delay the cost of creating an object until it is really needed, or to protect the object from unauthorized access.
 * This design pattern is used when the cost of creating an object is expensive and the object may not be used at all, or when the object is remote and needs to be accessed locally.
 * The proxy object is responsible for creating the real object and managing its lifetime. It also provides the same interface as the real object, 
 * so the client code does not need to know whether it is using the real object or the proxy object.
 * The main benefits of the Proxy design pattern are that it provides lazy initialization, allows for remote access to an object, and provides a way to control access to an object. 
 * It also makes it easier to change the implementation of an object without changing the client code.
 */
class Proxy : public Image {
    private:
    std::string fileName;
    RealImage* realImage;

    public:
    Proxy(const std::string& filename) : fileName(filename), realImage(nullptr){}

    void display() override {
        if(realImage == nullptr){
            realImage = new RealImage(fileName);
        }
        realImage->display();
    }
    ~Proxy(){
        delete realImage;
    }
};

int main(){
    Image* img_1 = new Proxy("img1.jpj");
    Image* img_2 = new Proxy("img2.jpj");

    img_1->display();
    img_2->display();

    return 0;
}
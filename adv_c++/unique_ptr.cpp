#include<iostream>
#include<memory>

class Entity{


public:
    void Print(){
        std::cout << "Just printing" << std::endl;
    }
    Entity(){
        std::cout << "Object created" << std::endl;
    }

    ~Entity(){
        std::cout << "Object destroyed" << std::endl;
    }

};

int main(){

    std::unique_ptr<Entity> en = std::make_unique<Entity>();
    std::cout << "Addr of first unique ptr " << &en << std::endl;
    std::unique_ptr<Entity> en1 = std::move(en);
    std::cout << "Addr of first unique ptr " << &en1 << std::endl;
    en->Print();
}
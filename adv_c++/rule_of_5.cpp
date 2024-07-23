#include <iostream>

using namespace std;

class RuleOfFive {
    private:
    int* data;

    public:
    //constructor
    RuleOfFive(int d) : data(new int(d)) {}

    //destructor
    ~RuleOfFive(){
        delete data;
    }

    //copy constructor
    RuleOfFive(const RuleOfFive& other) : data(other.data){}

    //copy assignment operator
    RuleOfFive& operator=(const RuleOfFive& other){
        data = other.data;
    }

    //move constructor
    RuleOfFive(RuleOfFive&& other) noexcept : data(other.data){
        other.data = nullptr;
    }

    //move assignment operator
    RuleOfFive& operator=(RuleOfFive&& other) noexcept {
        if(this != &other){
            delete data;
            data = other.data;
            other.data = nullptr;
        }
    }
};

int main(){
    return 0;
}
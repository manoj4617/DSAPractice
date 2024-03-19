#include<iostream>
#include<memory>

template<typename T>
class smart_ptr{
    private:
        T *_ptr;
    public:
        
        //to avoid implicit conversion
        explicit smart_ptr(T* ptr = nullptr)
            : _ptr(ptr){}
        

        smart_ptr(const smart_ptr&) = delete;
        smart_ptr& operator=(const smart_ptr&) = delete;

        T& operator*() const{
            return *_ptr;
        }

        T* operator->() const{
            return _ptr;
        }

        smart_ptr(smart_ptr&& other) : _ptr(other._ptr){
            other._ptr = nullptr;
        }

        smart_ptr& operator=(smart_ptr&& other){
            if(this != &other){
                delete _ptr;
                _ptr = other._ptr;
                other._ptr = nullptr;
            }
            return *this;
        }

        ~smart_ptr(){
            delete _ptr; 
        }
};

int main(){

    int ptr_val;
    std::cin >> ptr_val;
   
    smart_ptr<int> ptr(new int(ptr_val));
    

    std::cout << *ptr << std::endl;
}
#include<iostream>
#include<utility>

int main(){

    std::string str1 = "manoj";
    std::string str2 = "anuj";

    std::cout << "str 1 " << str1 << std::endl;
    std::cout << "str 2 " << str2 << std::endl;

    //copying
    str1 = str2;
    std::cout << "str 1 " << str1 << std::endl;
    std::cout << "str 2 " << str2 << std::endl;

    //moving
    std::cout << "after moving" << std::endl;
    str2 = std::move(str1);
    std::cout << "str 1 " << str1 << std::endl;
    std::cout << "str 2 " << str2 << std::endl;

}
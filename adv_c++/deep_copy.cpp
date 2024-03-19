#include <iostream>
#include <cstring> 

class MyString {
public:
  MyString(const char* str) {
    length_ = std::strlen(str);
    str_ = new char[length_ + 1];
    std::strcpy(str_, str);
  }

  MyString(const MyString& other) {
    length_ = other.length_;
    str_ = new char[length_ + 1];
    std::strcpy(str_, other.str_);
  }

  ~MyString() { delete[] str_; }

public:
  size_t length_;
  char* str_;
};

int main() {
  MyString s1("Hello");
  MyString s2 = s1;
  std::cout << &s1.str_ <<"\n"<< &s2.str_ << std::endl;
  return 0;
}

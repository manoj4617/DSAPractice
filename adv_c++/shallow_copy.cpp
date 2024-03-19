#include <iostream>

class MyClass {
public:
  MyClass(int x, int* y) : x_(x), y_(y) {}

  MyClass(const MyClass& other) : x_(other.x_), y_(other.y_) {}

public:
  int x_;
  int* y_;
};

int main() {
  int y = 5;
  MyClass c1(10, &y);
  MyClass c2 = c1; 
  std::cout << *(&c2.y_) << std::endl << &y;  
  return 0;
}

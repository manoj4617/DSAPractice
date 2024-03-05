#include <iostream>

class MyFunctor {
public:
  void operator()(int x) const {
    std::cout << "x = " << x << std::endl;
  }
};

int main() {
  MyFunctor f;
  f(5);
  return 0;
}

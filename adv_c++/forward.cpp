#include <iostream>
#include <utility>

template <typename T>
void foo(T&& x) {
  bar(std::forward<T>(x));
}

void bar(int&& x) {
  std::cout << x << std::endl;
}

int main() {
  int x = 5;
  foo(x);  // calls bar(int&)
  foo(5);  // calls bar(int&&)
  return 0;
}

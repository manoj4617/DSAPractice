#include <iostream>
#include <functional>
#include <vector>

int main() {
  int x = 5;
  std::vector<std::reference_wrapper<int>> v{x};
  std::cout << v[0] << std::endl;  // prints 5
  x = 6;
  std::cout << v[0] << std::endl;  // prints 6
  return 0;
}

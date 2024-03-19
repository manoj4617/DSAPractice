#include <algorithm>
#include <vector>
#include<iostream>

struct MyCompare {
  bool operator()(int x, int y) const { return x > y; }
};

int main() {
  std::vector<int> v{3, 1, 4, 2};
  for(auto i : v){
    std::cout << i << "\t";
  }
  std::cout << "\n";
  std::sort(v.begin(), v.end(), MyCompare());
  for(auto i : v){
    std::cout << i << "\t";
  }
  return 0;
}

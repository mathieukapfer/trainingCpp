
#include <list>
#include <vector>
#include <iostream>


void loop()
{
  // C++11
  std::list<int> aList = { 1, 2, 3, 4, 5 };

  // C++97
  for (std::list<int>::iterator it=aList.begin(); it!= aList.end(); it++) {
    std::cout << *it;
  }
  std::cout << std::endl;

  // C++11
  for (auto it=aList.begin(); it!= aList.end(); it++) {
    std::cout << *it;
  }
  std::cout << std::endl;

  // C++11
  for (const auto & val : aList) {
    std::cout << val;
  }
  std::cout << std::endl;

}

int main() {
  loop();
  return 0;

}

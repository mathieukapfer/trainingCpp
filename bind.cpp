#include <functional>
#include <iostream>

struct F {
  int operator() (int a, int b) {
    return a + b;
  }
} f;

int add(int a, int b) {
  return a + b;
}

int main()
{

  // call functor
  std::cout << f(1,2) << std::endl;

  // bind function - keep one parameter
  std::function<int (int)> g = std::bind(f, std::placeholders::_1, 1000);  // work with functor i.e. function object
  std::function<int (int)> h = std::bind(add, std::placeholders::_1, 2000);// work with function

  // call binding function
  std::cout << g(1) << std::endl;
  std::cout << h(1) << std::endl;

  return 0;
}

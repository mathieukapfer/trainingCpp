#include <functional>
#include <iostream>

// functor
struct F {
  int operator() (int a, int b) {
    return a + b;
  }
} f;

// classic function
int add(int a, int b) {
  return a + b;
}

// overloaded functions
float add_(float a, float b) {
  return a + b;
}

int add_(int a, int b) {
  return a + b;
}

int main()
{

  // call functor
  std::cout << f(1,2) << std::endl;

  // bind function - keep one parameter
  std::function<int (int)> f1 = std::bind(f, std::placeholders::_1, 1000);  // work with functor i.e. function object
  std::function<int (int)> f2 = std::bind(add, std::placeholders::_1, 2000);// work with function

  // use auto
  auto f3 = std::bind(f, std::placeholders::_1, 3000);

  // resolve overloaded function
  auto f4 = std::bind<int>(add,  std::placeholders::_1, 4000);// work with overloaded function

  // call binding function
  std::cout << f1(1) << std::endl;
  std::cout << f2(1) << std::endl;
  std::cout << f3(1) << std::endl;
  std::cout << f4(1) << std::endl;

  return 0;
}

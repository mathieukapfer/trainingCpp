#include <iostream>

template<typename T>
void funct_caller(const T &param) {
  param.callme();
}

struct CallMe {
  void callme() const {
    std::cout << "Hello" << std::endl;
  }
};

// Following template specialisation are equivalente:
//  - none => use *implicite* declaration
//  - or one of the following *explicite* declaration:
template void funct_caller<CallMe>(const CallMe & param);
// template void funct_caller<>(const CallMe & param);
// template void funct_caller(const CallMe & param);

int main(int argc, char *argv[]) {
  // Following template function are equivalent
  funct_caller<CallMe>(CallMe());
  funct_caller<>(CallMe());
  funct_caller(CallMe());
  return 0;
}
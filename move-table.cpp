#include <iostream>

class BigClass
{

 private:
  static const int TABLE_SIZE=10;
  int *table;

 public:
  //! Default constructor
  BigClass():table(new int[TABLE_SIZE]) {
  }

  //! Move constructor
  BigClass(BigClass &&other) noexcept {
    std::cout << "Move constructor called" << std::endl;
    // copy the pointer ;
    table = other.table;
    // reset copied pointer
    other.table = nullptr;
    // => the ownerchip has changed
  };

};

int main( )
{
  BigClass b1;
  BigClass b2 = std::move(b1);

  return 0;
}

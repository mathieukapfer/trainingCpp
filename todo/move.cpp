#include <stdio.h>
#include <iostream>
#include <utility>
#include <stdlib.h>
#include <string.h>

#define CALLED(str) printf("%s %s called\n",__FUNCTION__, str)

class Name
{
 public:
  //! Default constructor
  Name();

  //! Copy constructor
  Name(const Name &other);

  //! Move constructor
  Name(Name &&other) noexcept;

  //! Destructor
  virtual ~Name() noexcept;

  //! Copy assignment operator
  Name& operator=(const Name &other);

  //! Move assignment operator
  Name& operator=(Name &&other) noexcept;



 protected:
 private:
};

#define TABLE_SIZE 10

class MyClass {
 public:
  // default const
  MyClass(int val=0) {
    CALLED("default");
    this->val=val;
    this->ptr_val = &this->val;
    this->bigTable = (int *)malloc(sizeof(int) * TABLE_SIZE);
    this->bigTable[0] = val;
  };

  // dest
  ~MyClass() {
    CALLED("");
  };

  // copy const
  MyClass(const MyClass &a) {
    CALLED("copy");
    this->val= a.val;
    this->ptr_val = &(this->val);
    this->bigTable = (int *)malloc(sizeof(int) * TABLE_SIZE);
    memcpy(this->bigTable,a.bigTable, sizeof(int) * TABLE_SIZE);
  }

  // move construtor
  MyClass(const MyClass &&cls) {
    CALLED("move");
  }

  // copy assign. operator '='
  MyClass &operator=(const MyClass &a) {
    CALLED("copy");
    this->val= a.val;
    this->ptr_val = &(this->val);
    memcpy(this->bigTable,a.bigTable, sizeof(int) * TABLE_SIZE);
    return *this;
  };

  // move assign. operator '='
  MyClass &operator=(MyClass &&a) {
    CALLED("move");
    this->val= a.val;
    this->ptr_val = &(this->val);
    this->bigTable = a.bigTable;
    a.bigTable = NULL;
    return *this;
  };

  void toString() {
    std::cout << "val: " << this->val;
    std::cout << ", *ptr_val: " << (this->ptr_val != NULL)?*this->ptr_val:-1;
    std::cout << ", bigTable: " << this->bigTable;
    std::cout << ", *bigTable: " << (this->bigTable != NULL)?*this->bigTable:-1;
    std::cout << std::endl;

  }

  int val;
  int *ptr_val;
  int *bigTable;
};


int main(int argc, char *argv[])
{

  MyClass a(1);
  MyClass b(2);
  MyClass c(a);

  printf("val:%d=%d\n",a.val, *a.ptr_val);
  printf("val:%d=%d\n",b.val, *b.ptr_val);
  printf("val:%d=%d\n",c.val, *c.ptr_val);
  b = a;
  printf("val:%d=%d\n",b.val, *b.ptr_val);

  MyClass d;
  d = std::move(c);
  printf("val:%d=%d\n",d.val, *d.ptr_val);

  a.toString();
  b.toString();
  c.toString();
  d.toString();

  return 0;
}

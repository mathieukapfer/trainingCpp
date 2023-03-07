
int foo_const(const int *y) {
  return *y;
}


int foo(int *y) {
  return *y;
}

int main(int argc, char *argv[])
{

  // const
  int x = 1;
  const int a = 5;
  const int b = 3;
  // a = 2; // ko

  // ptr to const
  const int *ptr = &a;
  ptr = &b;
  ptr = &x; // ok !
  // *ptr = 10; // ko

  // const ptr
  int * const ptr2 = &x;
  // ptr2 = &a; // => ko as ptr is const
  const int * const ptr3 = &a;


  // const as parameter
  // foo(ptr); // ko
  // foo(&a);  // ko
  foo_const(&a);

  // const as qualifier of method of class

  // const as qualifier as return element

  return 0;
}

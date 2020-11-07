#include <iostream>
using namespace std;

#define LOG_ENTER(str) cout << __FUNCTION__ << " " str " " << endl;

// a class with explicit constructors and assignment operator
//   C++11 add the Move constructor and  Move assignment operator
class MyClass
{
 public:
  //! Default constructor
  MyClass():m_i(0)
    { LOG_ENTER("default"); }

  //! Another constructor
  MyClass(int i): m_i(i)
    { LOG_ENTER("1 parameters"); }

  //! Copy constructor
  MyClass(const MyClass &other)
    { LOG_ENTER("copy");}

  //! Move constructor (C++11)
  MyClass(MyClass &&other) noexcept
    { LOG_ENTER("move"); }

  //! Destructor
  virtual ~MyClass() noexcept
    { LOG_ENTER(""); }

  //! Copy assignment operator
  MyClass& operator=(const MyClass &other)
    { LOG_ENTER("copy"); return *this;}

  //! Move assignment operator (C++11)
  MyClass& operator=(MyClass &&other) noexcept
    { LOG_ENTER("move"); return *this;}

  private:
  int m_i;

};

// a class with no 'user defined' constructor
class MyClass2
{
 public:
  int i;
  int *ptr;
};

// same as above
struct MyClass3
{
  // following attribute are public
  int i;
  int *ptr;
};


int main(int argc, char *argv[])
{
  // test constr
  MyClass c;               // default constr
  MyClass x();             // ! warning this is the declaration of a function !
  MyClass d(c);            // copy constr
  MyClass e(std::move(c)); // move constr
  MyClass f1(2);           // user defined constr with 1 parameter
  MyClass f2{1};           // same as above

  // test assignment operator
  d = e;                   // copy assignment operator
  e = std::move(d);        // move assignment operator

  // test aggregate initialization (do no call any constructor):
  //  - when no user defined constructor exist
  //  - when attributes are public
  MyClass2 g {999, nullptr};
  cout << "g.i:" << g.i << " g.ptr:" << g.ptr << endl;

  return 0;
}

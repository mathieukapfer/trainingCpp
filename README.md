# Training C++11
  - [class](#class)
  - [function](#function)
  - [template](#template)

## Class
### Canonical class declaration
<table>
<tr>
<th> C++98 style </th>
<th> C++11 style </th>
</tr>
<tr>
<td>

<div markdown="1">

```C++
class MyClass
{
 public:
  //! Default constructor
  MyClass();

  //! Copy constructor
  MyClass(const MyClass &other)

  //! Assignment operator
  MyClass& operator=(const MyClass &other)

  //! Destructor
  virtual ~MyClass();

};

```

</div>
</td>
<td>
<div markdown="1">

```C++
class MyClass
{
 public:
  //! Default constructor
  MyClass() = default;

  //! Copy constructor
  MyClass(const MyClass &other) = default;

  //! Move constructor
  MyClass(MyClass &&other) noexcept = default;

  //! Destructor
  virtual ~MyClass() noexcept = default;

  //! Copy assignment operator
  MyClass& operator=(const MyClass &other) = default;

  //! Move assignment operator
  MyClass& operator=(MyClass &&other) noexcept = default;

};
```

</div>
</td>
</tr>
</table>

C++11 new features:
  - add `move` constructor and `move` assignment operator
  - allow to define constructor, destructor, assignment each by
    - `= default`: keep the default behavour
    - `= delete`: forbidden the operation
  - allow to qualify a methode with
    - `override`: forbidden the overload
    - `final`: forbidden derivation


### Move

C++11 provide the move constructor and move assignment operator

#### declaration and explicite call
Hereafter is how the declaration looks like and when it is used (note that the 'move' implementation are not effective here)

<table>
  <tr>
  <td>

<div markdown="1">

```C
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
```

</div>
</td>
<td>
<div markdown="1">

```C++
int main(int argc, char *argv[])
{
  // test constr
  MyClass c;               // default constr
  MyClass x();             // ! warning this is the declaration
                           //   of a function !
  MyClass d(c);            // copy constr
  MyClass e(std::move(c)); // move constr
  MyClass f1(2);           // user defined constr with 1 parameter
  MyClass f2{1};           // same as above
}

```

With the following definition:

`#define LOG_ENTER(str) cout << __FUNCTION__ << " " str " " << endl;`

the execution produce:

```
MyClass default
MyClass copy
MyClass move
MyClass 1 parameters
MyClass 1 parameters
operator= copy
operator= move
~MyClass
~MyClass
~MyClass
~MyClass

```
</div>
</td>
</tr>
</table>


#### implementation when class contains pointer

The idea behind the `move` constructor is to tranfer the ownerchip of pointer (or stl container) of the class instead of copy them. Hence, we save a copy that may cost cpu.

Hereafter is a good implementation when the class carry a pointer

```C++
class BigClass
{

 private:
  static const int TABLE_SIZE=100;
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

}
```

#### implementation when class contain stl container

Just use the slt `std::move(x)` methode on each member.

#### explicite VS implicite call : the concept of RVALUE

##### implicit call
 `move` constructor or operator is automatically called by compiler on RVALUE

##### explicit call
 `move` can be explicitly called by `std::move` (that return a RVALUE!)

<table>
  <tr>
  <td>
  <div markdown="1">

```C++

#include <vector>
#include <iostream>

// a function to demonstrate the implicite call
//  of move operator
std::vector<int> getVector() {
  std::vector<int> tmp = {4, 5, 6};
  return tmp;
}

// helper to display container
#define display(v, msg)                         \
  std::cout << std::endl << msg ": " << #v "="; \
  for (int i:v) {std::cout << i << " ";};

int main(int argc, char *argv[])
{

  std::vector<int> v1 = {1, 2, 3};
  std::vector<int> v2, v3;

  display(v1,"after init");

  // explicity called
  v2 = std::move(v1);
  display(v1, "after move");
  display(v2, "after move");

  // implicilty called
  v3 = getVector();
  display(v3, "after fct ");

  return 0;
}

```

</div>
</td>
<td>
<div markdown="1">

```
make move-getvector && ./move-getvector
g++     move-getvector.cpp   -o move-getvector

after init: v1=1 2 3
after move: v1=
after move: v2=1 2 3
after fct : v3=4 5 6

```

</div>
</td>
</tr>
</table>

## Function

### Functor (C++98) and Lamdba expression (C++11)

Definition
 - a functor is a object with overload of operator `()`
 - a lambda expression is a function without name. It is also called anonymous function

The two pieces of code do the same thing
  - create and initialize a vector of 3 int
  - display it

<table>
<tr>
<th> C++98 style </th>
<th> C++11 style </th>
</tr>
<tr>
<td>

<div markdown="1">

```C++

#include <algorithm>  // for_each (C++98)
#include <vector>
#include <iostream>

using namespace std;


// functor
struct F {
  void operator() (int i) {
    cout << i << endl;
  };
} f;

// classic function
void fct(int i) {
  cout << ' ' << i << endl;
}

int main()
{
  vector<uint> v;

  v.push_back(1);
  v.push_back(2);
  v.push_back(3);

  // use functor
  for_each (v.begin(), v.end(), f);

  // use classic function
  for_each (v.begin(), v.end(), fct);

  return 0;
}

```

</div>
</td>
<td>
<div markdown="1">

```C
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int main()
{
  // C++11: initialisation list
  //        work with stl container
  vector<int> v = {1, 2, 3};

  // C++11: use lambda expression
  //        (i.e. anonymous function)
  for_each
    (v.begin(), v.end(),
       [] (int item) {cout << item << endl;});

}
```

</div>
</td>
</tr>
</table>


### More on lamda expression : the closure

In lamba functon, the syntaxe `[]` is called the ''closure''.

It define how to capture local variables : by reference, by value, all variables, only one.

<table>
  <tr>
  <td>

<div markdown="1">

| syntaxe | meaning |
|:--------|:--------|
| `[]` | no capture |
| `[x, &y]` | x by value, y by reference |
| `[=]` | all by value |
| `[&]` | all by reference |
| `[&, x]` | all by reference except x|
| `[=, &x]` | all by value except x|

</div>
</td>
<td>
<div markdown="1">

```C
int main()
{
  // stl container
  vector<int> v = {1, 2, 3};

  // lambda funct
  // with capture (of local variable)
  int sum = 0;

  for_each
    (v.begin(), v.end(),
      [&sum] (int item) {sum += item;});

  cout << "sum:" << sum << endl;
}
```

</div>
</td>
</tr>
</table>

### Bind

The `std::bind` function is part of  `<functional>`.

It allow to create a new fonction by wrapping an existing one i.e changing the signature, in order to reduce the number of parameters.

The binded function may be a function, functor, or method of object.


```C
#include <functional>
#include <iostream>

// function
int add(int a, int b) {
  return a + b;
}

int main()
{

  // call functor
  std::cout << f(1,2) << std::endl;

  // bind function - keep one parameter (the second one), replace the first one by 1000
  std::function<int (int)> add_1000 = std::bind(add, std::placeholders::_1, 1000);

  // call binding function
  std::cout << add_1000(1) << std::endl;

  return 0;
}
```

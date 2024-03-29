https://mathieukapfer.github.io/trainingCpp

# C++11
1. The generated Toc will be an ordered list
{:toc}

## Loop

### Initialization
Stl container with initialisation list (as table)

<table>
<tr>
<th> C++98 style </th>
<th> C++11 style </th>
</tr>
<tr>
<td>

<div markdown="1">

```c++
  std::vector<int> v;

  v.push_back(1);
  v.push_back(2);
  v.push_back(3);
```

</div>
</td>
<td>
<div markdown="1">

```c++
    // stl container with initialisation list (as table)
  std::vector<int> v = {1, 2, 3};
```

</div>
</td>
</tr>
</table>


### Type inference and range-based for loop
Nice and consise way to write loop ! 
<table>
<tr>
<th> C++98 style </th>
<th> C++11 style </th>
</tr>
<tr>
<td>

<div markdown="1">

```c++
  for (std::vector<int>::iterator it=v.begin(); 
       it != v.end(); it++) {
    std::cout << *it << std::endl;
  }
```

</div>
</td>
<td>
<div markdown="1">

```c++
  for (auto i: v) {
    std::cout << i << std::endl;
  }
```

</div>
</td>
</tr>
</table>

This is not only cosmetic consideration, but also [simplier ASM !](https://godbolt.org/#z:OYLghAFBqd5TKALEBjA9gEwKYFFMCWALugE4A0BIEAZgQDbYB2AhgLbYgDkAjF%2BTXRMiAZVQtGIHgBYBQogFUAztgAKAD24AGfgCsp5eiyahUAUgBMAIUtXyKxqiIEh1ZpgDC6egFc2TEABmLXJ3ABkCJmwAOT8AI2xSEAAOcgAHdCViFyYvX38gkIys5yEIqNi2BKTUh2wnHJEiFlIiPL8A4PtsR1KmJpaicpj4xJT7Ztb2gq6lSaHIkaqx5IBKe3QfUlROLktAyNRfHABqM0CPADd6klJz3DMtAEFHp8v0AkwTzHQAfSV0BxfgB3MgAawgkSIq3ONmer3enxOaVI6B2SiUv2I2DYSggGCYcxOc0wIBA1ycZHOHih90sADYThTVmcAOxwp4nLknFg%2BEjEgBeZ0CABEmfUAHRZAXYCAwwIc7knQSkCAksnS7C/IgnAjCsVaWG64UeQVGgi2Wwsszs15KpU/f6ArWg0gQilmACsVgtnpF8sV3JtItewdeXHW9G4nv4AS4OnI6G4Hkt1mJm222DOFkCfHIRG0EfWYJAnpCUa40n4bFLITjCaTXH4ShAIQL8Yj5DgsBQGBw%2BGIZEo1DojFYHG4ecEwjEEk4MjkwmUak0HfI%2BgshmMplTdjqDVcEHc0wCFlS4UWlWqIFZ6Uy2SEJ5AZ7vJRywyvY1v%2B76Aym3g6Z9ah6G5GnmD9RiSb95ifF85kGCDlig9YAS2HZuH2Q5jizakKVuOl4WeREvkdAEgVdCEoQDUMiI%2BL4UTRbAMSxIgcTxAkiXVckbipC5aUCB4LEZZk2UDLkVQgXl%2BWxNgThAcVUGtW1nntblSOdEFwUhVi2GolSg1ZEN4UM8NI2jWNC0TZNd3TNCcJzCx%2BHbHRVnWJBsBYHAkjlQxuCrcgazLch634Rtm1bfNC1c8gS2kT0JXpABOHhEq0ektC0T0LAsFLAl8rhAgstcwsijt1m7ZA0EBNIGESYd8Wq2qkiObceGCHhyBwS4CB2AA1AhsGBAB5NJmEnfhR1Y0gWwgOJLLiSIWgAT3G8gFtYUglqGuJdBuVaMDYDhhCGph6BWtccDYbdJAughSFA64WzXbB1HqPldjzKEeks%2BgCDiUhlq8HBLKIUgCBrXhOxoIxgCUfrBpGsbIcXURxEkBdp0UFQNEs/QOqMEw0F3Qw/pbSB1nQNI%2BiegBaIbCu6XocjcJhPAAgoOovCpIIMYoH1ydmAg6vm%2BkQ68Op/MDBifCWQIPfpwMvHmJZgwWDHg1oxbGHgUIzdCdfymNgssxsTnUZJ6Rp%2BlpBOFqTBONqJS0CUeBOCAB1ubNc1WJyoq7XtGsYCgqAatgaqDtACeANqtA6rqeuweHhtGuMpwYKaZrmtd1uW1ac827bdqcfbASOogTrOyzLuu3YE0Ie6GkeyyXre1jVq%2BisE1%2B/7AawWunLBiG%2BHWaGWFhpPEdTib5FndHZEx5ccbXDct0J8xrFsEm4jJnzKep7g6YZyXD2PNXOdZrWkmF%2B8%2Bhl19%2Bcv9W5d/VX8iFxnQKEP8Fm5pD1dfwCKsEJKz/gbVCmZnxmS4EbEKVkuBmwtlbG2dtgAO0CE7F2bsPZkC9hYH2pUXL%2BxAIQGgNB6qY1nvOee8hF6ri7kgFs%2BMGEkJoEQJao0IqkAYc%2BcgXClAsLYRwrQUCYEm24CKAgpCThJ0SAgy21tbZRzQRg12lwlByKQYo7cyjnZ5mckWcg7lPJjB8iWT00gJTBGSFoRKgREqJWkKyVk1jWT0nyv5GsPAMrG2KtwcKm59HRQrI5HxDY/EEIMdcaazNpBAA%3D%3D)


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

```c++
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

```c++
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
    - `= default`: keep the default behavior
    - `= delete`: forbidden the operation
  - allow to qualify a method with
    - `override`: check the methode overwrite parent's one
    - `final`: forbidden derivation

### Usages
Let's inspect when each canonical method is called.
(note that the implementations are not effective here, but just logged)

<table>
  <tr>
  <td>

<div markdown="1">

```c++
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

```c++
int main(int argc, char *argv[])
{
  // test constr
  MyClass c;               // default constr
  MyClass d(c);            // copy constr
  MyClass e(std::move(c)); // move constr
  MyClass f1(2);           // user defined constr with 1 parameter
  MyClass f2{1};           // same as above

  // test assignment operator
  d = e;                   // copy assignment operator
  e = std::move(d);        // move assignment operator

  // ! warning the code below is the declaration
  //   of a function. It do nothing !
  MyClass x();
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


### Move

C++11 provide the move constructor and move assignment operator

#### implementation when class contains pointer

The idea behind the `move` constructor is to transfer the ownership of pointer (or stl container) of the class instead of copy them. Hence, we save a copy that may cost CPU.

Hereafter is a good implementation when the class carry a pointer

```c++
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

#### implementation when class contains stl container

Just use the slt `std::move(x)` methode on each member.

#### implicit call on RVALUE

Definition:
  - implicit call: `move` constructor or operator is automatically called by compiler on RVALUE. An example of RVALUE is the return value of a function. (more on expression, gvalue, rvalue, lvalue, ...[here](https://docs.microsoft.com/fr-fr/cpp/cpp/lvalues-and-rvalues-visual-cpp?view=msvc-160)
  - explicit call: `move` can be explicitly called with `std::move` (that return a RVALUE!)

<table>
  <tr>
  <td>
  <div markdown="1">

```c++

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

### Functor and Lambda expression

Definition:
 - a functor(C++98) is a object with overload of operator `()`
 - a lambda expression (C++11) is a function without name, also called anonymous function.

Usage:
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

```c++

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

```c++
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


### Lambda expression closure

The syntax `[]` if a lambda function is called the ''closure''.

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

```c++
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

It allow to create a new function by wrapping an existing one i.e changing the signature, in order to reduce the number of parameters.

The bind object may be a function, functor, or method.


```c++
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

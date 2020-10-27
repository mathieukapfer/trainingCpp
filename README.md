# Training C++11

## Function

### Functor (C++98) and Lamdba expression (i.e. anonymous function)  (C++11)

The two pieces of code do the same thing
  - create and initialize a vector with 3 int
  - display it

<table>
<tr>
<th> C++98 style </th>
<th> C++11 style </th>
</tr>
<tr>
<td>

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
</td>
<td>

```C++
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
</td>
</tr>
</table>


### More on lamda expression : the closure

In lamba functon, the syntaxe ```[]``` is called the ''closure''.

It define how to capture local variables : by reference, by value, all variables, only one.

<table>
  <tr>
  <td>

| syntaxe | meaning |
| ------- | --------|
| ```[]``` | no capture |
| ```[x, &y]``` | x by value, y by reference |
| ```[=]``` | all by value |
| ```[&]``` | all by reference |
| ```[&, x]``` | all by reference except x|
| ```[=, &x]``` | all by value except x|

  </td>
  <td>

```C++
int main()
{
  // stl container with initialisation list (as table)
  vector<int> v = {1, 2, 3};

  // lambda funct with capture (of local variable)
  int sum = 0;

  for_each
    (v.begin(), v.end(), [&sum] (int item) {sum += item;});

  cout << "sum:" << sum << endl;
}
```
  </td>
  </tr>
  </table>


### Bind

The ```std::bind``` function is part of  ```<functional>```.

It allow to create a new fonction by wrapping an existing one i.e changing the signature, in order to reduce the number of parameters.

The binded function may be a function, functor, or method of object.


``` C
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

### Move

C++11 provide the move constructor and move assignator

Hereafter is how the declaration looks like and when it is used 

<table>
  <tr>
  <td>
    
```C++
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

  </td>
  <td>
  
```C++
int main(int argc, char *argv[])
{
  // test constr
  MyClass c;               // default constr
  MyClass x();             // ! warning this is the declaration of a function !
  MyClass d(c);            // copy constr
  MyClass e(std::move(c)); // move constr
  MyClass f1(2);           // user defined constr with 1 parameter
  MyClass f2{1};           // same as above
}

```
With the following definition: 

  ```#define LOG_ENTER(str) cout << __FUNCTION__ << " " str " " << endl;```
  
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

  </td>
  </tr>
  </table>




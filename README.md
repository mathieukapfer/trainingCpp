# Training C++11

## Function

### Functor (C++98) and Lamdba function  (C++11)

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

  // C++11: use lambda function 
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

In lamba functon, the syntaxe '[]' is called the ''closure''. 

It define how to capture local variables : by reference, by value, all variables, only one.

<table>
  <tr>
  <td>
    
| syntaxe | meaning |
| ------- | --------|
| [] | no capture |
| [x, &y] | x by value, y by reference |
| [=] | all by value |
| [&] | all by reference |
| [&, x] | all by reference except x|
| [=, &x] | all by value except x|
  
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
  </tr>
  </td>
  </table>


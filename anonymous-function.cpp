
#include <algorithm>  // for_each (C++98)
#include <functional> // std::function (C++11)
#include <vector>
#include <iostream>

using namespace std;

int main()
{

  // stl container with initialisation list (as table)
  vector<int> v = {1, 2, 3};

  // lambda function
  for_each
    (v.begin(), v.end(), [] (int item) {cout << item << endl;});

  // lambda funct with capture (of local variable)
  int sum = 0;
  for_each
    (v.begin(), v.end(), [&sum] (int item) {sum += item;});
  cout << "sum:" << sum << endl;




  // just for the fun:
  // ------------------
  // declare a lamda function and assign it to a std::function
  // .. that capture 'sum' as reference
  sum = 0;
  std::function <int (vector<int>)> sum2 =
                 [&sum] (vector<int> v2) -> int {
                   for(int i : v2) {
                     sum += i;
                   }
                   return sum;
                 };
  cout << "sum:" << sum2(v) << endl;;

  // .. that capture 'sum' as reference, v as value
  sum = 0;
  std::function <int ()> sum3 =
    [&sum, v] () -> int {
      for(int i : v) {
        sum += i;
      }
      return sum;
    };

  cout << "sum:" << sum3() << endl;;;

  return 0;
}

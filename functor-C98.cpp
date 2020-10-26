
#include <algorithm>  // for_each (C++98)
#include <vector>
#include <iostream>

using namespace std;

struct F {
  void operator() (int i) {
    cout << i << endl;
  };
} f;

void fct(int i) {
  cout << ' ' << i << endl;
}

int main()
{
  cout << "c++98 :" << endl;

  vector<uint> v;

  v.push_back(1);
  v.push_back(2);
  v.push_back(3);

  for_each (v.begin(), v.end(), f);
  for_each (v.begin(), v.end(), fct);

  return 0;
}

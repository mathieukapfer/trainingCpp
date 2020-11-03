// source: https://en.cppreference.com/w/cpp/language/range-for
// source: https://en.cppreference.com/w/cpp/algorithm/for_each

// for_each macro: since C++98   (part of <algorithm>)
// new form of for: since C++11

#include <iostream>

#define TABLE_SIZE 100

int main(int argc, char *argv[])
{

  int table[TABLE_SIZE];

  // fill the table: C++98
  for (int i = 0; i < TABLE_SIZE; ++i) { table[i] = i;  }

  // new way in C++11
  // =================
  //  - fill the table - loop by reference
  int val=0;
  for (int &c:table) {c=val++;}

  //  - read the table - loop by value
  for (int c:table) {std::cout << c << " ";}

  return 0;
}

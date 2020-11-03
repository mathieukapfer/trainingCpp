
#include <vector>
#include <iostream>

// a function to demonstrate the explicity call of move operator
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

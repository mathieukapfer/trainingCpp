#include <iostream>

using namespace std;

float mydiv(float a, float b) {
  if (b==0)
    throw "div by 0";
  else
    return (a/b);
}

void caller(float a, float b) {
  try {
    float c = mydiv(a,b);
    cout << "res:" << c << endl;
  } catch (const char *msg) {
    cout << msg << endl;
  }
}

int main(int argc, char *argv[])
{

  caller(1.0, 0.0);
  caller(1.0, 3.0);

  return 0;
}

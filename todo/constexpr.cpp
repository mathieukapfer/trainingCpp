#include <iostream>
#include <x86intrin.h>

static __inline__ unsigned long GetCC(void)
{
#if 0
  unsigned a, d;
  asm volatile("rdtsc" : "=a" (a), "=d" (d));
  return ((unsigned long)a) | (((unsigned long)d) << 32);
#else
  return __rdtsc();
#endif
}

// classical function
int fibo1(int n) {
  if (n > 1)
    return  fibo1(n-1) + fibo1(n-2);
  else
    return n;
}

// with template (evaluate at run time)
template<const int N>
int fibo2() {return fibo2<N-1>() + fibo2<N-2>();}
template<> int fibo2<1>(){return 1;}
template<> int fibo2<0>(){return 0;}


// with template & constexpr (evaluate at compile time)
template<const int N>
constexpr int fibo3() {return fibo2<N-1>() + fibo2<N-2>();}
template<> constexpr int fibo3<1>(){return 1;}
template<> constexpr int fibo3<0>(){return 0;}


// with 'constexpr if' (C++17, cflag: -std=c++17)
template<const int N>
constexpr int fibo4() {
  if constexpr (N > 2)
    return fibo4<N - 1>() + fibo4<N - 2>();
  else
    return N;
}

// or simplier
constexpr int fibo5(int n) {
  if (n > 2)
    return fibo5(n - 1) + fibo5(n - 2);
  else
    return n;
}


#define FIBO 40

int main(int argc, char *argv[])
{

  unsigned long start, stop;
  int res;

  // call function
  start = GetCC();
  res = fibo1(FIBO);
  stop = GetCC();
  std::cout << res << "(" << (stop-start)  << ")" << std::endl;

  // use huge run time !
  start = GetCC();
  res = fibo2<FIBO>();
  stop = GetCC();
  std::cout << res << "(" << (stop-start)  << ")" << std::endl;

  // use huge run time !
  start = GetCC();
  res = fibo3<FIBO>();
  stop = GetCC();
  std::cout << res << "(" << (stop-start)  << ")" << std::endl;

  // use huge run time !
  start = GetCC();
  res = fibo4<FIBO>();
  stop = GetCC();
  std::cout << res << "(" << (stop-start)  << ")" << std::endl;

  start = GetCC();
  res = fibo5(FIBO);
  stop = GetCC();
  std::cout << res << "(" << (stop-start)  << ")" << std::endl;


  return 0;
}

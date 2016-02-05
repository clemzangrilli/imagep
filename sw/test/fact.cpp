
#include <iostream>
#include <iomanip>

int factorial(int n) {
  if (n == 0)
    return 1;
  return n * factorial (n - 1);
}

int main () {
  int i;
  int n;
  for (i = 0; i < 10; ++i) {
    n = factorial (i);
    std::cout << "factorial(" << i << ") = " << n << std::endl;
  }
  return 0;
}

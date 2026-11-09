#include <iostream>

int NumberParser(char* pointer) {
  int n = 0;
  while (*pointer != '\0') {
    n = 10 * n + (*pointer - '0');
    ++pointer;
  }
  return n;
}

int main(int argc, char* argv[]) {
  if (argc != 2) {
    return 1;
  }

  int n = NumberParser(argv[1]);

  double* a = new double[n];
  double* b = new double[n];

  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
  }

  for (int i = 0; i < n; ++i) {
    std::cin >> b[i];

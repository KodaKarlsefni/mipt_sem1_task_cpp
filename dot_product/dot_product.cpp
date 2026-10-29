#include <iostream>

int main(int argc, char *argv[]) {

  if (argc != 2) {
    return 1;
  }
  char *pointer = argv[1];
  if (*pointer < '0' || *pointer > '9') {
    return 1;
  }
  int n = 0;
  while (*pointer != '\0') {
    n = 10 * n + (*pointer - '0');
    pointer++;
  }

  double *a = new double[n];
  double *b = new double[n];

  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
  }

  for (int i = 0; i < n; ++i) {
    std::cin >> b[i];
  }

  double dot_product = 0.0;

  for (int i = 0; i < n; ++i) {
    dot_product += a[i] * b[i];
  }

  std::cout << dot_product;

  delete[] a;
  delete[] b;
}

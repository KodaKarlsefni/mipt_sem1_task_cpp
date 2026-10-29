#include <iostream>

#ifdef _WIN32
#include <fcntl.h>
#include <io.h>
#endif

void Swap(int &a, int &b) {
  int c = a;
  a = b;
  b = c;
}

int GCD(int a, int b) {
  while (b > 0) {
    int t = b;
    b = a % b;
    a = t;
  }
  return a;
}

int main(int argc, char *argv[]) {

#ifdef _WIN32
  _setmode(_fileno(stdout), _O_BINARY);
#endif

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

  int *numbers = new int[n];

  for (int i = 0; i < n; ++i) {
    std::cin >> numbers[i];
  }

  int k;
  std::cin >> k;

  k = ((k % n) + n) % n;

  for (int t = 0; t < GCD(n, k); ++t) {
    for (int cnt = 1; cnt < n / GCD(n, k); ++cnt) {
      Swap(numbers[t], numbers[(t + k * cnt) % n]);
    }
  }

  for (int i = 0; i < n; ++i) {
    std::cout << numbers[i] << '\n';
  }

  for (int i = 0; i < n - 1; ++i) {
    std::cout << numbers[i] << ' ';
  }
  std::cout << numbers[n - 1] << '\n';
  delete[] numbers;
}

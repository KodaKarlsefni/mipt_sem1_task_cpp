#include <iostream>

void Swap(int& a, int& b) {
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

int NumberParser(char* pointer) {
  int n = 0;
  while (*pointer != '\0') {
    n = 10 * n + (*pointer - '0');
    ++pointer;
  }
  return n;
}

void CyclicShift(int n, int k, int* numbers) {
  for (int t = 0; t < GCD(n, k); ++t) {
    for (int cnt = 1; cnt < n / GCD(n, k); ++cnt) {
      Swap(numbers[t], numbers[(t + 1LL * k * cnt) % n]);
    }
  }
}

void PrintAnswer(int n, int* numbers) {
  for (int i = 0; i < n; ++i) {
    std::cout << numbers[i] << '\n';
  }

  for (int i = 0; i < n - 1; ++i) {
    std::cout << numbers[i] << ' ';
  }
  std::cout << numbers[n - 1] << '\n';
}

int main(int argc, char* argv[]) {
  if (argc != 2) {
    return 1;
  }
  int n = NumberParser(argv[1]);

  int* numbers = new int[n];

  for (int i = 0; i < n; ++i) {
    std::cin >> numbers[i];
  }

  int k;
  std::cin >> k;

  k = ((k % n) + n) % n;

  CyclicShift(n, k, numbers);

  PrintAnswer(n, numbers);

  delete[] numbers;
}

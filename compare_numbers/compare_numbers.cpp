#include <iostream>

struct Number {
  char* start;
  int sign;
  int integer_digits;
  int digit_count;

  Number(char* x) {
    start = x;
    sign = 1;
    if (*start == '-') {
      start++;
      sign = -1;
    } else if (*start == '+') {
      start++;
    }

    integer_digits = 0;
    while (start[integer_digits] != '\0' and start[integer_digits] != '.') {
      integer_digits++;
    }
    digit_count = integer_digits;
    if (start[digit_count] == '.') {
      digit_count++;
    }
    while (start[digit_count] != '\0') {
      digit_count++;
    }
  }
};

int main(int argc, char* argv[]) {
  if (argc != 3) {
    return 1;
  }

  Number number_1(argv[1]);
  Number number_2(argv[2]);

  if (number_1.sign > number_2.sign) {
    std::cout << "greater" << '\n';
    return 0;
  }
  if (number_1.sign < number_2.sign) {
    std::cout << "less" << '\n';
    return 0;
  }
  if (number_1.sign == 1) {
    if (number_1.integer_digits > number_2.integer_digits) {
      std::cout << "greater" << '\n';
      return 0;
    }
    if (number_1.integer_digits < number_2.integer_digits) {
      std::cout << "less" << '\n';
      return 0;
    }
    for (int i = 0; i < std::min(number_1.digit_count, number_2.digit_count);
         ++i) {
      if (number_1.start[i] > number_2.start[i]) {
        std::cout << "greater" << '\n';
        return 0;
      }
      if (number_1.start[i] < number_2.start[i]) {
        std::cout << "less" << '\n';
        return 0;
      }
    }
    if (number_1.digit_count < number_2.digit_count) {
      std::cout << "less" << '\n';
      return 0;
    }
    if (number_1.digit_count > number_2.digit_count) {
      std::cout << "greater" << '\n';
      return 0;
    }
    std::cout << "equal" << '\n';
    return 0;
  }

  if (number_1.integer_digits > number_2.integer_digits) {
    std::cout << "less" << '\n';
    return 0;
  }
  if (number_1.integer_digits < number_2.integer_digits) {
    std::cout << "greater" << '\n';
    return 0;
  }
  for (int i = 0; i < std::min(number_1.digit_count, number_2.digit_count);
       ++i) {
    if (number_1.start[i] > number_2.start[i]) {
      std::cout << "less" << '\n';
      return 0;
    }
    if (number_1.start[i] < number_2.start[i]) {
      std::cout << "greater" << '\n';
      return 0;
    }
  }
  if (number_1.digit_count < number_2.digit_count) {
    std::cout << "greater" << '\n';
    return 0;
  }
  if (number_1.digit_count > number_2.digit_count) {
    std::cout << "less" << '\n';
    return 0;
  }
  std::cout << "equal" << '\n';
}

// 进制转换

#include <iostream>
#include <stack>

int main(int argc, char *argv[]) {
  std::stack<int> digits;

  int a;

  std::cout << "please input a: " << std::endl;
  std::cin >> a;

  bool negative = (a < 0);
  if (negative) {
    a = -a;
  }

  int b = a;
  while (b > 0) {
    digits.push(b % 8);
    b = b / 8;
  }

  b = 0;
  while (!digits.empty()) {
    b = b * 10 + digits.top();
    digits.pop();
  }

  std::cout << "result: " << b << std::endl;

  return 0;
}
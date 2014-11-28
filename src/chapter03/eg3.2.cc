// 判断括号

#include <iostream>
#include <stack>

bool match() {
  std::stack<char> parens;
  char c;

  while (std::cin >> c) {
    switch (c) {
      case '(':
        parens.push(c);
        break;
      case ')':
        // parens.pop() 前必须检查 parens.empty()
        if (parens.empty()) {
          return false;
        } else {
          parens.pop();
        }
        break;
      default:
        break;
    }
  };

  return parens.empty();
}

int main(int argc, char *argv[]) {
  std::cout << match() << std::endl;

  return 0;
}
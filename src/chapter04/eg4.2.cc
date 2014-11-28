#include <iostream>
#include <vector>

void GetSteps(const std::string &str, std::vector<int> &steps) {
  if (str.size() == 0) {
    return;
  }

  steps.push_back(-1);
  int i = 0, j = -1;
  while (i < str.length()) {
    if (j == -1 || str[i] == str[j]) {
      ++i;
      ++j;
      if (str[i] == str[j]) {
        steps.push_back(steps[j]);
      } else {
        steps.push_back(j);
      }
    } else {
      j = steps[j];
    }
  }
}

int main(int argc, char *argv[]) {
  std::string str;
  std::vector<int> steps;

  while (true) {
    std::cout << "please input string: " << std::endl;
    std::cin >> str;
    steps.clear();
    GetSteps(str, steps);

    for (auto iter = steps.begin(); iter != steps.end(); iter++) {
      std::cout << *iter << " ";
    }
    std::cout << std::endl;
  }

  return 0;
}
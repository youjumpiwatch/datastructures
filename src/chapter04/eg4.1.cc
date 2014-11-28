#include <iostream>
#include <string>

int index(std::string &first, std::string &second) {
  // i <= first.size() - second.size()
  for (int i = 0; i <= first.size() - second.size(); i++) {
    int k;
    for (k = 0; k < second.size(); k++) {
      if (first[i + k] != second[k]) {
        break;
      }
    }
    if (k == second.size()) {
      return i;
    }
  }

  return -1;
}

int main(int argc, char *argv[]) {
  std::string first, second;

  std::cout << "please input the first string: " << std::endl;
  std::cin >> first;
  std::cout << "please input the second string: " << std::endl;
  std::cin >> second;

  std::cout << "index: " << index(first, second) << std::endl;

  return 0;
}
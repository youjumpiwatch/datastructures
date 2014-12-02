#include <iostream>
#include <vector>

void GetSteps(const std::string &str, std::vector<int> &steps) {
  if (str.size() == 0) {
    return;
  }

  steps.clear();
  steps.push_back(-1);

  for (int i = 1; i < str.length(); i++) {
    int j = i - 1, k = steps[j];
    while (k >= 0 && str[j] != str[k]) {
      k = steps[k];
    }
    steps.push_back(k + 1);
  }
}

void GetStepsImproved(const std::string &str, std::vector<int> &steps) {
  if (str.empty()) {
    return;
  }

  steps.clear();
  steps.push_back(-1);

  int j = 0, k = -1;
  while (j < str.length() - 1) {
    if (k == -1 || str[j] == str[k]) {
      j++;
      k++;
      if (str[j] == str[k]) {
        steps.push_back(steps[k]);
      } else {
        steps.push_back(k);
      }
    } else {
      k = steps[k];
    }
  }
}

//void GetStepsYan(const std::string &str, std::vector<int> &steps) {
//  if (str.empty()) {
//    return;
//  }
//
//  steps.clear();
//
//  int i = 0, j = -1;
//  steps.push_back(-1);
//  while (i < str.length() - 1) {
//    if (j == -1 || str[i] == str[j]) {
//      ++i;
//      ++j;
//      if (str[i] != str[j]) {
//        steps.push_back(j);
//      } else {
//        steps.push_back(steps[j]);
//      }
//    } else {
//      j = steps[j];
//    }
//  }
//}

void Print(const std::vector<int> &steps) {
  for (auto iter = steps.begin(); iter != steps.end(); iter++) {
    std::cout << *iter << "\t";
  }
  std::cout << std::endl;
}

int main(int argc, char *argv[]) {
  std::string str;
  std::vector<int> steps;

  str = "ABCDABD";
  GetSteps(str, steps);
  Print(steps);
  GetStepsImproved(str, steps);
  Print(steps);

  str = "AAAB";
  GetSteps(str, steps);
  Print(steps);
  GetStepsImproved(str, steps);
  Print(steps);

  return 0;
}
#include <iostream>
#include <vector>
#include <tgmath.h>

class Item {
 public:
  Item(int coef, int exp) : coef(coef), exp(exp), next(NULL) {}
  virtual ~Item() {}

  int coef;
  int exp;
  Item *next;
};

int main(int argc, char *argv[]) {
  int a_length = -1, b_length = -1;
  Item *a_list = NULL, *b_list = NULL, *a_pivot = NULL, *b_pivot = NULL;

  do {
    std::cout << "please input length of A array:" << std::endl;
    std::cin >> a_length;
  } while (a_length <= 0);

  a_list = new Item(0, 0);
  a_pivot = a_list;
  for (int i = 0; i < a_length; i++) {
    std::cout << "please input " << i << " item:" << std::endl;
    int coef, exp;
    std::cin >> coef >> exp;
    a_pivot->next = new Item(coef, exp);
    a_pivot = a_pivot->next;
  }

  do {
    std::cout << "please input length of B array:" << std::endl;
    std::cin >> b_length;
  } while (b_length <= 0);

  b_list = new Item(0, 0);
  b_pivot = b_list;
  for (int i = 0; i < b_length; i++) {
    std::cout << "please input " << i << " item:" << std::endl;
    int coef, exp;
    std::cin >> coef >> exp;
    b_pivot->next = new Item(coef, exp);
    b_pivot = b_pivot->next;
  }

  a_pivot = a_list;
  b_pivot = b_list->next;

  while (b_pivot != NULL) {
    if (a_pivot->next == NULL) {
      a_pivot->next = new Item(b_pivot->coef, b_pivot->exp);
    } else {
      // 插入 insert
      if (a_pivot->next->exp < b_pivot->exp) {
        Item *next = a_pivot->next;
        a_pivot->next = new Item(b_pivot->coef, b_pivot->exp);
        a_pivot->next->next = next;
      } else if (a_pivot->next->exp > b_pivot->exp) {
        a_pivot = a_pivot->next;
        continue;
      } else {
        a_pivot->next->coef += b_pivot->coef;
      }
    }
    // 这里注意要把 a_pivot　提前一位
    a_pivot = a_pivot->next;
    Item *next = b_pivot->next;
    delete b_pivot;
    b_pivot = next;
  }

  for (a_pivot = a_list->next; a_pivot != NULL; a_pivot = a_pivot->next) {
    std::cout << "coef: " << a_pivot->coef << ", exp:" << a_pivot->exp << std::endl;
  }

  return 0;
}
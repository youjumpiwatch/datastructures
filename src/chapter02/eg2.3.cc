#include <iostream>
#include <vector>

class Node {
 public:
  Node(int x) : data(x), next(NULL) {}
  virtual ~Node() {}

  int data;
  Node *next;
};

int main(int argc, char *argv[]) {
  int a_length, b_length;
  std::vector<int> a_array, b_array;

  std::cout << "Please input length of A array: " << std::endl;
  std::cin >> a_length;
  std::cout << "Please input length of B array: " << std::endl;
  std::cin >> b_length;

  for (int i = 0; i < a_length; i++) {
    int data;
    std::cin >> data;
    a_array.push_back(data);
  }

  for (int i = 0; i < b_length; i++) {
    int data;
    std::cin >> data;
    b_array.push_back(data);
  }

  Node *head = new Node(0), *pivot = head;
  for (auto iter = a_array.begin(); iter != a_array.end(); iter++) {
    pivot->next = new Node(*iter);
    pivot = pivot->next;
  }

  for (auto iter = b_array.begin(); iter != b_array.end(); iter++) {
    Node *fast = head->next, *slow = head;
    while (fast != NULL && fast->data != *iter) {
      slow = fast;
      fast = fast->next;
    }
    if (fast == NULL) {
      slow->next = new Node(*iter);
    } else {
      Node *next = fast->next;
      delete fast;
      slow->next = next;
    }
  }

  pivot = head->next;
  while (pivot != NULL) {
    std::cout << pivot->data << " ";
    pivot = pivot->next;
  }
  std::cout << std::endl;

  return 0;
}
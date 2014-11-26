// arithmetic of pointers.

#include <stdio.h>

int main(int argc, char *argv[]) {
  int array[2] = { 1, 2 };

  int *a = array;
  void *b = array;

  printf("address of a+1: %lx\n", a + 1);
  printf("address of b+1: %lx\n", b + 1);

  return 0;
}
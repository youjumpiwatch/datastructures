#include <iostream>
#include <vector>

class Triplet {
 public:
  int i;
  int j;
  int value;

  Triplet(int i, int j, int value) : i(i), j(j), value(value) {}
  virtual ~Triplet() {}
};

class Matrix {
 public:
  std::vector<Triplet> points;
  int m, n, t;
};

void PrintMatrix(const Matrix &matrix) {
  int i = 0, j = 0, k = 0;
  for (i = 0; i < matrix.m; i++) {
    for (j = 0; j < matrix.n; j++) {
      if (i == matrix.points[k].i && j == matrix.points[k].j) {
        std::cout << matrix.points[k].value;
        k++;
      } else {
        std::cout << 0;
      }
      if (j == matrix.n - 1) {
        std::cout << std::endl;
      } else {
        std::cout << "\t";
      }
    }
  }
}

void Transpose(Matrix &matrix) {

}

int main(int argc, char *argv[]) {
  Matrix matrix;

  matrix.m = 12;
  matrix.n = 10;

  for (int i = 0; i < matrix.m; i++) {
    for (int j = 0; j < matrix.n; j++) {
      int value = (i + j) % 7;
      if (value == 0) {
        continue;
      }
      Triplet triplet(i, j, value);
      matrix.points.push_back(triplet);
      matrix.t++;
    }
  }

  PrintMatrix(matrix);

  return 0;
}
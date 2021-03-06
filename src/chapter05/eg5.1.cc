#include <iostream>
#include <vector>
#include <algorithm>

template<typename T>
inline void swap2(T &x, T &y)
{
  T tmp = x;
  x = y; y = tmp;
}

class Triplet {
 public:
  int i;
  int j;
  int value;

  Triplet(int i, int j, int value) : i(i), j(j), value(value) {}
  virtual ~Triplet() {}

  Triplet &operator=(const Triplet &other) {
    i = other.i;
    j = other.j;
    value = other.value;
    return *this;
  }
};

bool comparator(const Triplet &first, const Triplet &second) {
  return first.i < second.i || (first.i == second.i && first.j < second.j);
}

class Matrix {
 public:
  std::vector<Triplet> points;
  int m, n, t;

  Matrix &operator=(const Matrix &other) {
    points = other.points;
    m = other.m;
    n = other.n;
    t = other.t;
    return *this;
  }
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

void TransposeMatrix(Matrix &matrix) {
  for (auto iter = matrix.points.begin(); iter != matrix.points.end(); iter++) {
    swap2(iter->i, iter->j);
  }
  swap2(matrix.m, matrix.n);
  std::sort(matrix.points.begin(), matrix.points.end(), comparator);
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

  std::cout << std::endl;

  Matrix matrix2 = matrix;
  TransposeMatrix(matrix2);
  PrintMatrix(matrix2);

  return 0;
}
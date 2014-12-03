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

  bool operator==(const Triplet &other) {
    return i == other.i && j == other.j && value == other.value;
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

void FastTransposeMatrix(Matrix &matrix, Matrix &newmatrix) {
  std::vector<int> count(matrix.n, 0);

  for (auto iter = matrix.points.begin(); iter != matrix.points.end(); iter++) {
    if (iter->j < matrix.n - 1) {
      count[iter->j + 1]++;
    }
  }

  for (int i = 1; i < count.size(); i++) {
    count[i] += count[i - 1];
  }

  for (auto iter = matrix.points.begin(); iter != matrix.points.end(); iter++) {
    int pos = count[iter->j];
    newmatrix.points[pos].i = iter->j;
    newmatrix.points[pos].j = iter->i;
    newmatrix.points[pos].value = iter->value;
    count[iter->j]++;
  }

  newmatrix.m = matrix.n;
  newmatrix.n = matrix.m;
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

  std::cout << std::endl;

  Matrix matrix3 = matrix;
  FastTransposeMatrix(matrix, matrix3);
  PrintMatrix(matrix3);

  std::cout << "Result: " << (matrix2 == matrix3);

  return 0;
}
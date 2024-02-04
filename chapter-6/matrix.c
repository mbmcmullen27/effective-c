#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>

int matrix_sum(size_t rows, int m[][4]) {
  int sum = 0;
  for (size_t i = 0; i < rows; i++) {
    for (size_t j = 0; j < 4; j++) {
      sum += m[i][j];
    }
  }
  return sum;
}

int main(void) {
  int m1[5][4] = {
    {1, 1, 1, 1},
    {1, 1, 1, 1},
    {1, 1, 1, 1},
    {1, 1, 1, 1},
    {1, 1, 1, 1}
  };
  int m2[100][4] = { 0 };
  int m3[2][4] = { 0 };
  printf("m1 = %d.\n", matrix_sum(5, m1));
  printf("m2 = %d.\n",  matrix_sum(100, m2));
  printf("m3 = %d.\n", matrix_sum(2, m3));
}

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>

#define ARRAY_LEN(a) (sizeof(a) / sizeof((a)[0]))
#define MATRIX_ROW_LEN(m) (ARRAY_LEN(m))
#define MATRIX_COL_LEN(m) (ARRAY_LEN((m)[0]))

#define MATRIX_SUM(m) matrix_sum(MATRIX_ROW_LEN(m), m)
#define MATRIX_PRINT(m) matrix_print(MATRIX_ROW_LEN(m), m)

int matrix_sum(size_t rows, int m[][4]) {
  int sum = 0;
  for (size_t i = 0; i < rows; i++) {
    for (size_t j = 0; j < 4; j++) {
      sum += m[i][j];
    }
  }
  return sum;
}

static void matrix_print(size_t rows, int m[][4]) {
  for (size_t i = 0; i < rows; i++) {
    for (size_t j = 0; j < 4; j++) {
      printf("%3d ", m[i][j]);
    }
    puts("");
  }
}

int main(void) {
  int m1[5][4] = {
    {1, 1, 1, 1},
    {1, 1, 1, 1},
    {1, 1, 1, 1},
    {1, 1, 1, 1},
    {1, 1, 1, 1}
  };
  int m2[25][4] = { 0 };
  int m3[2][4] = { 0 };

  /* fill m2 with numbers from 1 to sizeof(m2), i.e. the expected sum is 5050 */
  for (size_t i = 0; i < MATRIX_ROW_LEN(m2); i++)
    for (size_t j = 0; j < MATRIX_COL_LEN(m2); j++)
      m2[i][j] = i * MATRIX_COL_LEN(m2) + j + 1;

  MATRIX_PRINT(m2);

  printf("m1 = %d.\n", MATRIX_SUM(m1));
  printf("m2 = %d.\n", MATRIX_SUM(m2));
  printf("m3 = %d.\n", MATRIX_SUM(m3));
}

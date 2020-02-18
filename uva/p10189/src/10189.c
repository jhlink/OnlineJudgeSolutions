/* https://onlinejudge.org/external/101/10189.pdf */

#include <stdio.h>
#include <stdlib.h>
#include <string.h> /* Memset*/
#include <stdint.h>
#include <math.h>

#define NDEBUG

uint32_t min_uint(uint32_t a, uint32_t b);
uint32_t max_uint(uint32_t a, uint32_t b);

void
print_array(uint32_t rows, uint32_t cols, char mn_mtx[static rows * cols])
{
  int t_row = 0;
  int t_col = 0;

  for ( t_row = 0; t_row < rows; ++t_row ) {
    for ( t_col = 0; t_col < cols; ++t_col ) {
      putchar(mn_mtx[( t_row * cols ) + t_col]);
    }

    putchar('\n');
  }
}

void
mark_cell(uint32_t row, uint32_t col, char mn_mtx[static row * col],
          uint32_t row_width, uint32_t col_width)
{
  if ( row < 0 || row >= row_width || col < 0 || col >= col_width) {
    return;
  }

  if ( mn_mtx[ row * col_width + col ] != '*' ) {
    mn_mtx[ row * col_width + col ]++;
  }
}

void
erase_matrix(uint32_t rows, uint32_t cols, char mn_mtx[static rows * cols])
{
  int t_row = 0;
  int t_col = 0;

  for (t_row = 0; t_row < rows; ++t_row) {
    for (t_col = 0; t_col < cols; ++t_col) {
      if ( mn_mtx[t_row * cols + t_col] == '.' ) {
        mn_mtx[t_row * cols + t_col] = '0';
      }
    }
  }
}

void
traverse_matrix(uint32_t rows, uint32_t cols, char mn_mtx[static rows * cols])
{


  int t_row = 0;
  int t_col = 0;

  erase_matrix(rows, cols, mn_mtx);

  for (t_row = 0; t_row < rows; ++t_row) {
    for (t_col = 0; t_col < cols; ++t_col) {
      if ( mn_mtx[t_row * cols + t_col] == '*' ) {
        /*Top row*/
        mark_cell(t_row - 1, t_col - 1, mn_mtx, rows, cols);
        mark_cell(t_row - 1, t_col, mn_mtx, rows, cols);
        mark_cell(t_row - 1, t_col + 1, mn_mtx, rows, cols);

        /*Mid row*/
        mark_cell(t_row, t_col - 1, mn_mtx, rows, cols);
        mark_cell(t_row, t_col + 1, mn_mtx, rows, cols);

        /*Bottom row*/
        mark_cell(t_row + 1, t_col - 1, mn_mtx, rows, cols);
        mark_cell(t_row + 1, t_col, mn_mtx, rows, cols);
        mark_cell(t_row + 1, t_col + 1, mn_mtx, rows, cols);
      }
    }
  }
}


void
process_input()
{
  int i = 0;
  uint32_t n_lines = 0;
  uint32_t m_cols = 0;
  int test = 1;
  char* array;

  while ( scanf("%u %u\n", &n_lines, &m_cols) == 2 ) {
    if ( !n_lines && !m_cols ) {
      break;
    } else if ( test > 1 ) {
      putchar('\n');
    }

    array = calloc(n_lines * m_cols + 1, sizeof(*array));

    printf("Field #%d:\n", test);

    for ( i = 0; i < n_lines; ++i) {
      fgets( array + (m_cols * i), m_cols + 2, stdin);
    }

    traverse_matrix(n_lines, m_cols, array);
    print_array(n_lines, m_cols, array);

    test++;
    free(array);
  }
}


int
main()
{
  process_input();
  return (0);
}

/* Helper functions */

uint32_t
max_uint(uint32_t a, uint32_t b)
{
  return a > b ? a : b;
}

uint32_t
min_uint(uint32_t a, uint32_t b)
{
  return a < b ? a : b;
}


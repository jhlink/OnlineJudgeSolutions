/* https://onlinejudge.org/external/1/100.pdf */

#include <stdio.h>
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
process_input()
{
  int i = 0;
  uint32_t n_lines = 0;
  uint32_t m_cols = 0;
  char array[100];

  while ( scanf("%u %u\n", &n_lines, &m_cols) == 2 ) {
    printf("%u %u\n", n_lines, m_cols);

    if ( !n_lines && !m_cols ) {
      break;
    }

    for ( i = 0; i < n_lines; ++i) {
      fgets( array + (m_cols * i), m_cols + 2, stdin);
    }

    print_array(n_lines, m_cols, array);
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


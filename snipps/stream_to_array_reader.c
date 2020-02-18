#include <stdio.h>

void
process_input()
{
  while ( scanf("%u %u\n", &n_lines, &m_cols) == 2 ) {

    int i = 0;
    uint32_t n_lines = 0;
    uint32_t m_cols = 0;
    char array[9000];

    for ( i = 0; i < n_lines; ++i) {
      fgets( array + (m_cols * i), m_cols + 2, stdin);
    }
  }
}

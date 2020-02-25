/* https://onlinejudge.org/external/7/706.pdf */

#include <stdlib.h> /* alloc funcs */
#include <string.h> /* memset*/
#include <stdint.h> /* (un)signed ints and limits */
#include <stdio.h>  /* putchar */

uint32_t min_uint(uint32_t a, uint32_t b);
uint32_t max_uint(uint32_t a, uint32_t b);

#define LCD_MATRIX_DIMEN 7
#define NUM_OF_DIGITS 10

/* LCD matrix addressed as follows.
 *     0
 *     -
 * 1 |   | 2
 *  3  -
 * 4 |   | 5
 *     -
 *     6
 */

static const char DIGIT_MATRIX[NUM_OF_DIGITS][LCD_MATRIX_DIMEN] = {
  /*       0    1    2    3    4    5    6        */
  /* 0 */ '-', '|', '|', ' ', '|', '|', '-', \
  /* 1 */ ' ', ' ', '|', ' ', ' ', '|', ' ', \
  /* 2 */ '-', ' ', '|', '_', '|', ' ', '-',
  /* 3 */ '-', ' ', '|', '_', ' ', '|', '-',
  /* 4 */ ' ', '|', '|', '_', ' ', '|', ' ',
  /* 5 */ '-', '|', ' ', '_', ' ', '|', '-',
  /* 6 */ '-', '|', ' ', '_', '|', '|', '-',
  /* 7 */ '-', ' ', '|', ' ', ' ', '|', ' ',
  /* 8 */ '-', '|', '|', '_', '|', '|', '-',
  /* 9 */ '-', '|', '|', '_', ' ', '|', '-'
};

void print_digits() {
  int i, j;
  int digit = 2;

  for ( digit = 0; digit < NUM_OF_DIGITS; ++digit ) {
    for ( i = 0; i < LCD_MATRIX_DIMEN; ++i ) {
      if ( i % 3 == 0 ) {
        putchar(' ');
        putchar(DIGIT_MATRIX[digit][i]);
        putchar(' ');
        putchar('\n');
      } else if ( 0 < i && i < 2) {
        putchar(DIGIT_MATRIX[digit][i]);
        putchar(' ');
        putchar(DIGIT_MATRIX[digit][i + 1]);
        putchar('\n');
      } else if ( 3 < i && i < 5) {
        putchar(DIGIT_MATRIX[digit][i]);
        putchar(' ');
        putchar(DIGIT_MATRIX[digit][i + 1]);
        putchar('\n');
      }
    }

    putchar('\n');
  }
}

void
process_input()
{
}


int
main()
{
  process_input();
  print_digits();
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


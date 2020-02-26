/* https://onlinejudge.org/external/7/706.pdf */

#include <stdlib.h> /* alloc funcs */
#include <string.h> /* memset*/
#include <stdint.h> /* (un)signed ints and limits */
#include <stdio.h>  /* putchar */

uint32_t min_uint(uint32_t a, uint32_t b);
uint32_t max_uint(uint32_t a, uint32_t b);

#define LCD_MATRIX_DIMEN 7
#define NUM_OF_DIGITS 10
#define MAX_DIGIT_LEN 9

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
  /* 2 */ '-', ' ', '|', '-', '|', ' ', '-',
  /* 3 */ '-', ' ', '|', '-', ' ', '|', '-',
  /* 4 */ ' ', '|', '|', '-', ' ', '|', ' ',
  /* 5 */ '-', '|', ' ', '-', ' ', '|', '-',
  /* 6 */ '-', '|', ' ', '-', '|', '|', '-',
  /* 7 */ '-', ' ', '|', ' ', ' ', '|', ' ',
  /* 8 */ '-', '|', '|', '-', '|', '|', '-',
  /* 9 */ '-', '|', '|', '-', ' ', '|', '-'
};

void
print_digits(int scale, char input_digits[MAX_DIGIT_LEN])
{
  int row_count = 2 * scale + 3;
  int col_count = scale + 2;
  int lcd_digit_len = strlen(input_digits);
  char *lcd_row = calloc(col_count * lcd_digit_len, sizeof(*lcd_row)) ;
  int i, j, digit_index, digit;

  for ( i = 0; i < row_count; ++i ) {
    for ( j = 0; j < lcd_digit_len; ++j ) {
      digit = input_digits[j] - '0';
      digit_index = j * (3 + scale);

      if ( (i % (scale + 1)) == 0 ) {
        int test = i / (scale + 1) * 3;
        lcd_row[digit_index++] = ' ';

        memset(lcd_row + digit_index, DIGIT_MATRIX[digit][test], scale);
        digit_index += scale;

        lcd_row[digit_index++] = ' ';
      } else if ( 0 < i && i < (scale + 1)) {
        lcd_row[digit_index++] = DIGIT_MATRIX[digit][1];

        memset(lcd_row + digit_index, ' ', scale);
        digit_index += scale;

        lcd_row[digit_index++] = DIGIT_MATRIX[digit][2];
      } else if ( (scale + 1) < i && i < (2 * (scale + 1))) {
        lcd_row[digit_index++] = DIGIT_MATRIX[digit][4];

        memset(lcd_row + digit_index, ' ', scale);
        digit_index += scale;

        lcd_row[digit_index++] = DIGIT_MATRIX[digit][5];
      }

      if ( j != lcd_digit_len - 1) {
        lcd_row[digit_index] = ' ';
      }
    }

    puts(lcd_row);
    memset(lcd_row, 0, row_count);
  }
}

void
process_input()
{
  int scale_size = 0;
  char input_digits[MAX_DIGIT_LEN] = { 0 };

  while ( scanf( "%d %s", &scale_size, input_digits) == 2 ) {
    if ( !scale_size ) {
      break;
    }

    print_digits(scale_size, input_digits);
    memset(input_digits, 0, MAX_DIGIT_LEN);
    putchar('\n');
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


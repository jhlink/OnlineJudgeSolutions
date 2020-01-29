/* https://onlinejudge.org/external/1/100.pdf */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <math.h>

#define NDEBUG

uint32_t min_uint(uint32_t a, uint32_t b);
uint32_t max_uint(uint32_t a, uint32_t b);

uint32_t
p100_helper(uint32_t i)
{
  uint32_t cycle_len = 1;
  uint32_t temp = i;

  while ( temp != 1) {
    if ( temp % 2) {
      temp = 3 * temp + 1;
    } else {
      temp >>= 2;
    } 

    cycle_len++;
  }

  return cycle_len;
}

void
p100(uint32_t start, uint32_t end)
{
  uint32_t max_len = 0;
  uint32_t i = min_uint(start, end);
  uint32_t target = max_uint(start, end);

  for (; i <= target; ++i) {
    uint32_t temp_cycle_len = p100_helper(i);

#ifdef DEBUG
    printf("Num:%d Len:%d\n", i, temp_cycle_len);
#endif

    max_len = max_uint(temp_cycle_len, max_len);

    printf("%u %u %u\n", start, end, max_len);
  }
}

void
process_input()
{
  uint32_t a = 0;
  uint32_t b = 0;

  while ( scanf("%u %u\n", &a, &b) == 2 ) {
    p100(a, b);
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
  return a > b ? a : b;
}


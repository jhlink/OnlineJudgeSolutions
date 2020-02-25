/* https://onlinejudge.org/external/1/100.pdf */

#include <stdlib.h> /* alloc funcs */
#include <string.h> /* memset*/
#include <stdint.h> /* (un)signed ints and limits */

#define NDEBUG

uint32_t min_uint(uint32_t a, uint32_t b);
uint32_t max_uint(uint32_t a, uint32_t b);

void
process_input()
{
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


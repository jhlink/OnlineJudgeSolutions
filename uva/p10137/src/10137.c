/* https://onlinejudge.org/external/101/10137.pdf */

#include <stdio.h>  /* scanf/printf */
#include <stdlib.h> /* alloc funcs */
#include <string.h> /* memset*/
#include <stdint.h> /* (un)signed ints and limits */
#include <math.h>   /* trunc */

#define NDEBUG

double min_double(double a, double b);
double max_double(double a, double b);
double trunc_to_hundreths(double ival);

void
parse_totals(uint32_t num_students, uint32_t totals[num_students], double *grand_total) {
    uint32_t i = 0;
    for ( i = 0; i < num_students; ++i ) {
      uint32_t dollars = 0;
      uint32_t cents = 0;
      scanf("%d.%d\n", &dollars, &cents);
      totals[i] = (dollars * 100) + cents;
      (*grand_total) += totals[i];
    }
}

void
process_input()
{
  int i = 0;
  uint32_t num_students = 0;

  uint32_t *student_totals = NULL;
  double sum = 0.0f;
  double low_sum = 0.0f;
  double high_sum = 0.0f;
  double avg = 0.0f;

  while ( scanf("%u\n", &num_students) == 1) {
    if ( !num_students ) {
      break;
    } else {
      student_totals = calloc( num_students, sizeof( *student_totals ));
      high_sum = 0.0f;
      low_sum = 0.0f;
      sum = 0.0f;
    }

    parse_totals(num_students, student_totals, &sum);  

    avg = (double)sum / num_students;

    for ( i = 0; i < num_students; ++i ) {
      if ( student_totals[i] >= avg ) {
        /* Type cast is important for truncation and precision */
        high_sum += (int) (student_totals[i] - avg) / 100.0;
      } else {
        low_sum += (int) (avg - student_totals[i]) / 100.0;
      }
    }

    sum =  max_double(low_sum, high_sum);
    printf("$%.2lf\n", sum);

    free(student_totals);
  }
}


int
main()
{
  process_input();
  return (0);
}

/* Helper functions */

double
trunc_to_hundreths(double ival) {
  return trunc( ival * 100 ) / 100;
}

double
max_double(double a, double b)
{
  return a > b ? a : b;
}

double
min_double(double a, double b)
{
  return a < b ? a : b;
}


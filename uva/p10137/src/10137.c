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

double
ceil_round_to_hundredth(double target)
{
  double int_target = target * 100;
  int_target = trunc(int_target);
  int_target /= 100;
  return int_target;
}

double
floor_round_to_hundredth(double target)
{
  double int_target = target * 100;
  int_target = trunc(int_target);
  int_target /= 100;

  return int_target;

}

void
process_input()
{
  int i = 0;
  uint32_t num_students = 0;
  double *student_totals = NULL;

  double grand_total_ceil = 0.0f;
  double grand_total_floor = 0.0f;
  double equalize_total = 0.0f;

  double neg_equalize_total_low = 0.0f;
  double neg_equalize_total_high = 0.0f;

  while ( scanf("%u\n", &num_students) == 1) {
    if ( !num_students ) {
      break;
    } else {
      student_totals = calloc( num_students, sizeof( *student_totals ));
    }

   grand_total_ceil = 0.0f;
   grand_total_floor = 0.0f;
   equalize_total = 0.0f;


    for ( i = 0; i < num_students; ++i ) {
      scanf("%lf\n", (student_totals + i));
      grand_total_ceil += ceil_round_to_hundredth(*(student_totals + i));
      grand_total_floor += floor_round_to_hundredth(*(student_totals + i));
    }

    grand_total_ceil = ceil_round_to_hundredth((grand_total_ceil * 100 /
                       num_students)) / 100;
    grand_total_floor = floor_round_to_hundredth((grand_total_floor * 100 /
                        num_students)) / 100;

    neg_equalize_total_low = 0.0f;
    neg_equalize_total_high = 0.0f;

    for ( i = 0; i < num_students; ++i ) {
      if ( student_totals[i] >= grand_total_floor ) {
        neg_equalize_total_high += trunc_to_hundreths(student_totals[i] - grand_total_ceil);
      } else {
        neg_equalize_total_low += trunc_to_hundreths(grand_total_floor - student_totals[i]);
      }
    }

    neg_equalize_total_low = trunc_to_hundreths(neg_equalize_total_low);
    neg_equalize_total_high = trunc_to_hundreths(neg_equalize_total_high);

    equalize_total =  max_double(neg_equalize_total_low, neg_equalize_total_high);
    printf("$%.2lf\n", equalize_total);

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


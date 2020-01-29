#include <stdio.h>

void
build_file_reader()
{
  uint32_t a = 0;
  uint32_t b = 0;
  FILE *fpi;
  fpi = fopen("input.txt", "r");

  if ( !fpi ) {
    printf("Can't read file");
    exit(EXIT_FAILURE);
  }

  rewind(fpi);

  while ( fscanf(fpi, "%u %u\n", &a, &b) == 2 ) {
    uint32_t c = p100(a, b);
    fprintf(fpo, "%u %u %u\n", a, b, c);
  }

  fclose(fpi);
}

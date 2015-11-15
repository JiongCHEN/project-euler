#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  size_t sum = 0, i = 0;
  for (i = 3; i < 1000; ++i) {
    if ( i % 3 == 0 || i % 5 == 0 )
      sum += i;
  }
  printf("%zu\n", sum);
  return 0;
}

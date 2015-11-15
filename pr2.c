#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 1024

size_t fib[MAXSIZE];

int main(int argc, char *argv[])
{
  fib[0] = 1;
  fib[1] = 2;
  size_t i, j;
  for (i = 2; i < MAXSIZE; ++i) {
    fib[i] = fib[i-1]+fib[i-2];
    if ( fib[i] > 4000000 )
      break;
  }
  printf("%zu\n", i);
  size_t sum = 0;
  for (j = 0; j < i; ++j)
    if ( fib[j] % 2 == 0 )
      sum += fib[j];
  printf("%zu\n", sum);
  return 0;
}

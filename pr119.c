#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAXSIZE 32

size_t arr[MAXSIZE];

static size_t digit_sum(const size_t x) {
  size_t sum = 0, y = x;
  while ( y ) {
    sum += y % 10;
    y /= 10;
  }
  return sum;
}

int main(int argc, char *argv[])
{
  size_t i, j, sum, cnt = 0;
  for (i = 10; ; ++i) {
    printf("this is %zu, %zu\n", i, cnt);
    sum = digit_sum(i);
    if ( sum == 1 )
      continue;
    for (j = 1; ; ++j) {
      if ( pow(sum, j) == i )
        arr[cnt++] = i;
      if ( pow(sum, j) > i )
        break;
    }
    if ( cnt == 30 )
      break;
  }
  printf("%zu\n", arr[0]);
  printf("%zu\n", arr[1]);
  printf("%zu\n", arr[2]);
  printf("%zu\n", arr[29]);
  return 0;
}

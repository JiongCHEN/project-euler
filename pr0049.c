#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

#define MAXSIZE 10000

int prime[10000];
int cnt = 0;

static int is_prime(const int x) {
  if ( x == 1 )
    return 0;
  if ( x == 2 || x == 3 )
    return 1;
  if ( x % 2 == 0 )
    return 0;
  int i;
  for (i = 3; i <= (int)sqrt(x); i += 2) {
    if ( x % i == 0 )
      return 0;
  }
  return 1;
}

int cmpfunc(const void *a, const void *b) {
   return (*(char*)a-*(char*)b);
}

static int have_same_digit(int x, int y) {
  char strx[256], stry[256];
  sprintf(strx, "%d", x);
  sprintf(stry, "%d", y);
  qsort(strx, strlen(strx), sizeof(char), cmpfunc);
  qsort(stry, strlen(stry), sizeof(char), cmpfunc);
  if ( strcmp(strx, stry) == 0 )
    return 1;
  return 0;
}

int main(int argc, char *argv[])
{
  int i, j, k;
  for (i = 1000; i < 10000; ++i) {
    if ( is_prime(i) )
      prime[cnt++] = i;
  }
  for (i = 0; i < cnt-2; ++i) {
    for (j = i+1; j < cnt-1; ++j) {
      for (k = j+1; k < cnt; ++k) {
        if ( 2*prime[j] == prime[i]+prime[k] && have_same_digit(prime[i], prime[j])
             && have_same_digit(prime[j], prime[k]) )
          printf("%d %d %d\n", prime[i], prime[j], prime[k]);
      }
    }
  }
  return 0;
}

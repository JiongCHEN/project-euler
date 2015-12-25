#include <stdio.h>

#define MAXSIZE 1000

static long int mod[MAXSIZE];
static long int r = 10000000000;

int main(int argc, char *argv[])
{
  int i = 0;
  for (i = 0; i < MAXSIZE; ++i) {
    mod[i] = 1;
    int j = i+1;
    while ( j-- ) {
      mod[i] = ((mod[i]%r)*((i+1)%r))%r;
    }
  }
  long int sum = 0;
  for (i = 0; i < MAXSIZE; ++i) {
    sum = (sum%r+mod[i]%r)%r;
  }
  printf("%ld\n", sum);
  return 0;
}

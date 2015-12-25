#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *strrev(char *str) {
  char *p1, *p2;
  if ( !str || !*str)
    return str;
  for (p1 = str, p2 = str+strlen(str)-1; p2 > p1; ++p1, --p2) {
    *p1 ^= *p2;
    *p2 ^= *p1;
    *p1 ^= *p2;
  }
  return str;
}

static int check(const int x) {
  char str[64], rev[64];
  sprintf(str, "%d", x);
  strcpy(rev, str);
  strrev(rev);
  if ( strcmp(str, rev) == 0 )
    return 1;
  return 0;
}

int main(int argc, char *argv[])
{
  int i, j;
  int prod;
  int ans = -1;
  for (i = 100; i < 1000; ++i) {
    for (j = 100; j < 1000; ++j) {
      prod = i*j;
      if ( check(prod) && prod > ans )
        ans = prod;
    }
  }
  printf("%d\n", ans);
  return 0;
}

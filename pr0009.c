#include <stdio.h>

int main(int argc, char *argv[])
{
  int a, b, c;
  for (a = 1; a < 1000; ++a) {
    for (b = a+1; b < 1000; ++b) {
      c = 1000-a-b;
      if ( b < c && a*a+b*b == c*c )
        printf("%d, %d, %d, prod: %d\n", a, b, c, a*b*c);
    }
  }
  return 0;
}

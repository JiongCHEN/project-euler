#include <stdio.h>
#include <string.h>
#include <math.h>

static int evaluate(const char *w) {
  int sum = 0, i;
  for (i = 0; i < strlen(w); ++i)
    sum += w[i]-'A'+1;
  return sum;
}

int main(int argc, char *argv[])
{
  FILE *fp = fopen("p042_words.txt", "r");
  if ( fp == NULL )
    printf("no such file\n");
  char word[64];
  size_t cnt = 0;
  while ( fscanf(fp, "\"%[^\"]\",", word) == 1 ) {
    int sum = evaluate(word);
    int sqroot = (int)sqrt(2*sum);
    if ( 2*sum == sqroot*(sqroot+1) )
      cnt++;
  }
  printf("%zu\n", cnt);
  return 0;
}

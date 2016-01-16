#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAXSIZE 1000

int prime[MAXSIZE];
int nbr, goal, cnt, sum;

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

static void gen_prime_list(const int num) {
  if ( num > MAXSIZE ) {
    printf("[ERROR] the given size is over capacity.\n");
    exit(EXIT_FAILURE);
  }
  int count = 0, i;
  for (i = 2; ; ++i) {
    if ( count == num )
      break;
    if ( is_prime(i) )
      prime[count++] = i;
  }
}

static void dfs(int curr) {
  if ( sum == goal ) {
    cnt++;
    return;
  }
  if ( curr == nbr )
    return;
  if ( sum > goal )
    return;
  int i;
  for (i = goal/prime[curr]; i >= 0; --i) {
    sum += i*prime[curr];
    dfs(curr+1);
    sum -= i*prime[curr];
  }
}

int main(int argc, char *argv[])
{
  nbr = 1000;
  gen_prime_list(nbr);

  int i;
  for (i = 10; ; ++i) {
    cnt = 0;
    sum = 0;
    goal = i;
    dfs(0);
    if ( cnt >= 5000 ) {
      printf("%d: %d\n", i, cnt);
      break;
    }
  }
  return 0;
}

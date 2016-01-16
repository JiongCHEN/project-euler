#include <stdio.h>

#define GOAL 200

int coin[8] = {1, 2, 5, 10, 20, 50, 100, 200};
int sum = 0;
int cnt = 0;

void dfs(const int curr) {
  if ( sum == GOAL ) {
    cnt++;
    return;
  }
  if ( curr == 8 )
    return;
  if ( sum > GOAL )
    return;
  int i;
  for (i = GOAL/coin[curr]; i >= 0; --i) {
    sum += i*coin[curr];
    dfs(curr+1);
    sum -= i*coin[curr];
  }
}

int main(int argc, char *argv[])
{
  dfs(0);
  printf("%d\n", cnt);
  return 0;
}

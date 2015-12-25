#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

static bool is_prime(const int x) {
  if ( x == 1 )
    return false;
  if ( x == 2 || x == 3 )
    return true;
  if ( x % 2 == 0 )
    return false;
  for (int i = 3; i <= (int)sqrt(x); i += 2) {
    if ( x % i == 0 )
      return false;
  }
  return true;
}

int main(int argc, char *argv[])
{
  for (int i = 9; i >= 4; --i) {
    char arr[10] = {'9', '8', '7', '6', '5', '4', '3', '2', '1', '\0'};
    do {
      size_t num = atoi(arr+9-i);
      if ( is_prime(num) ) {
        cout << i << ": " << num << endl;
        return 0;
      }
    } while ( prev_permutation(arr+9-i, arr+9) );
  }
  return 1;
}

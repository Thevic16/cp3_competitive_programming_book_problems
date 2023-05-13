/*
https://www.scaler.com/topics/double-in-c/

A double in c can be printed by both using %f and %lf. Both the %f format specifier and the %lf format specifier represent float and double. The printf() in c treats both float and double the same.

*/

#include <cstdio>
using namespace std;

int main() {
  double n;
  scanf("%lf", &n);
  printf("%7.3lf\n", n);
  return 0;
}

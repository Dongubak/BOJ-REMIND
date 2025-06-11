#include <iostream>
#define ll long long

using namespace std;

bool isBitSet(ll a, int b) {
  return (a & (1ull << b)) > 0;
}

int main(void) {
  int a = 3; /// 011
  int b = 12; /// 1100
  int c = 16; /// 10000

  cout << "3 : " << __builtin_ctz(a) << '\n';
  cout << "12 : " << __builtin_ctz(b) << '\n';
  cout << "16 : " << __builtin_ctz(c) << '\n';

  return 0;
}
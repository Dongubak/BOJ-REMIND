#include <bits/stdc++.h>

using namespace std;

int main(void) {
  int A[] = {999, 999, 999, 1000, 1000, 1000};

  auto iter = lower_bound(A, A + 6, 1000) - A;
  cout << iter;

  return 0;
}
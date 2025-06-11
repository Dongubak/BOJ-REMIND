#include <bits/stdc++.h>
#define all(x) begin(x), end(x)

using namespace std;

int main(void) {
  int n;
  cin >> n;

  vector<int> A(n, 0), pSum(n, 0);

  for(int i = 0; i < n; i++)
    cin >> A[i];
  
  pSum[0] = A[0];

  for(int i = 1; i < n; i++) {
    pSum[i] = pSum[i - 1] + A[i];
  }

  sort(all(pSum));

  int MIN = 1 << 30;

  for(int i = 1; i < n; i++) {
    int sub = pSum[i] - pSum[i - 1];
    MIN = min(abs(sub), MIN);
  }

  cout << MIN;

  return 0;
}
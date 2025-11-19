#include <bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(false); \
cin.tie(NULL);

using namespace std;

int A[500000];

int main(void) {
  FIO
  int n, m, t;
  cin >> n;

  for(int i = 0; i < n; i++) {
    cin >> A[i];
  }

  sort(A, A + n);

  cin >> m;

  for(int i = 0; i < m; i++) {
    int count = 0;
    cin >> t;
    
    auto i1 = lower_bound(A, A + n, t) - A;
    auto i2 = upper_bound(A, A + n, t) - A;

    cout << i2 - i1 << ' ';
  }
  

  return 0;
}
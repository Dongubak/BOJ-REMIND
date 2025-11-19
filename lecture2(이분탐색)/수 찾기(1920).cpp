#include <bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(false); \
cin.tie(NULL);

using namespace std;

int A[100000];

int main(void) {
  FIO
  int n;
  cin >> n;

  for(int i = 0; i < n; i++) {
    cin >> A[i];
  }

  sort(A, A + n);

  int m;
  cin >> m;

  int t;

  for(int i = 0; i < m; i++) {
    cin >> t;
    if(binary_search(A, A + n, t)) {
      cout << 1 << '\n';
    } else {
      cout << 0 << '\n';
    }
  }

  return 0;
}
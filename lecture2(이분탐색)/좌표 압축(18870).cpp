#include <bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(false); \
cin.tie(NULL);

using namespace std;

int A[1000000], B[1000000];

int main(void) {
  FIO
  int n;
  cin >> n;

  for(int i = 0; i < n; i++) {
    cin >> A[i];
    B[i] = A[i];
  }

  sort(B, B + n);
  auto last = unique(B, B + n) - B;
  // #ifdef ONLINE_JUDGE
  //   cout << "DEBUG" << '\n';
  //   cout << "sorted" << '\n';
  //   for(int i = 0; i < n; i++) {
  //     cout << B[i] << " ";
  //   }
  //   cout << '\n' << "A" << '\n';
  //   for(int i = 0; i < n; i++) {
  //     cout << A[i] << " ";
  //   }
  //   cout << '\n';
  // #endif

  for(int i = 0; i < n; i++) {
    int find = A[i];

    auto iter = lower_bound(B, B + last, find) - B;
    cout << iter << " ";
  }
  
  return 0;
}
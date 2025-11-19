#include <bits/stdc++.h>
#define  FIO ios_base::sync_with_stdio(false); \
cin.tie(NULL);
#define pp pair<int, int>
#define all(x) x.begin(), x.end()

using namespace std;

int main(void) {
  FIO
  int n, a, b;
  cin >> n;

  vector<pp> A(n);

  for(int i = 0; i < n; i++) {
    cin >> a >> b;

    A[i] = {a, b};
  }

  sort(all(A));

  for(auto& [a, b]: A) {
    cout << a << " " << b << '\n';
  }

  return 0;
}
#include <bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(false); \
cin.tie(NULL);
#define ll long long
using namespace std;

ll A[10000];

int main(void) {
  FIO

  ll n, k;
  cin >> k >> n;

  for(int i = 0; i < k; i++) {
    cin >> A[i];
  }

  ll l = 0, r = LLONG_MAX;
  ll tmax = -1;

  while(l < r) {
    ll m = l + (r - l) / 2;
    #ifdef ONLINE_JUDGE
      cout << "m : " << m << '\n';
    #endif

    ll sum = 0;
    for(int i = 0; i < k; i++) {
      sum += A[i] / m;
    }
    if(sum >= n) {
      l = m + 1;
      tmax = max(tmax, m);
    } else {
      r = m;
    }
  }

  cout << tmax;

  return 0;
}
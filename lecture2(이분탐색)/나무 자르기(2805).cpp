#include <bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(false); \
cin.tie(NULL);
#define ll long long
using namespace std;
#define t_pq priority_queue<int, vector<int>, greater<int>>

int tree[1000000];

int main(void) {
  FIO

  ll n, k;
  cin >> n >> k;

  for(int i = 0; i < n; i++) {
    cin >> tree[i];
  }

  sort(tree, tree + n);

  ll l = 0, r = 1'000'000'000;

  ll tmax = 0;

  while(l < r) {
    ll mid = (l + r) / 2;

    auto iter = lower_bound(tree, tree + n, mid) - tree;

    ll sum = 0;
    for(int i = iter; i < n; i++) {
      sum += (tree[i] - mid);
    }

    if(sum >= k) {
      l = mid + 1;
      tmax = max(tmax, mid);
    } else {
      r = mid;
    }
  }

  cout << tmax;

  return 0;
}
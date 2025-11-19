#include <bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(false); \
cin.tie(NULL);
#define ll long long
using namespace std;
#define t_pq priority_queue<int, vector<int>, greater<int>>

int blue[100000];

int main(void) {
  FIO

  int n, k;
  cin >> n >> k;

  for(int i = 0; i < n; i++) {
    cin >> blue[i];
  }

  ll l = 0, r = LLONG_MAX;
  ll gmin = LLONG_MAX;
  
  while(l < r) {
    ll m = l + (r - l) / 2;
    ll c = 1;
    ll tsum = 0;

    for(int i = 0; i < n; i++) {
      if(tsum + blue[i] > m) {
        c++;
        tsum = blue[i];
      } else if(tsum + blue[i] == m) {
        c++;
        tsum = 0;
      } else {
        tsum += blue[i];
      }
    }

    if(c <= k) {
      gmin = min(gmin, m);
      r = m;
    } else {
      l = m + 1;
    }
  }

  cout << gmin;

  return 0;
}
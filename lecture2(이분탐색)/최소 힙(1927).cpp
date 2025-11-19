#include <bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(false); \
cin.tie(NULL);
#define ll long long
using namespace std;
#define t_pq priority_queue<int, vector<int>, greater<int>>

int main(void) {
  FIO

  t_pq pq;

  int n, t;
  cin >> n;

  for(int i = 0; i < n; i++) {
    cin >> t;
    if(t == 0) {
      if(!pq.empty()) {
        cout << pq.top() << '\n';
        pq.pop();
      } else {
        cout << 0 << '\n';
      }
    } else {
      pq.push(t);
    }
  }

  return 0;
}
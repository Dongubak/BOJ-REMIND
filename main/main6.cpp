#include <bits/stdc++.h>
#define pp pair<int, int>

using namespace std;

int V, Q, s, d, w;

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> V >> Q;

  vector<vector<pp>> g(V + 1);

  for(int i = 0; i < V - 1; i++) {
    cin >> s >> d >> w;
    g[s].push_back({d, w});
    g[d].push_back({s, w});
  }
  int q1, q2;

  vector<vector<int>> sht(V + 1, vector<int>(V + 1, 1 << 30));

  for(int i = 1; i <= V; i++) {
    sht[i][i] = 0;
    priority_queue<pp, vector<pp>, greater<pp>> pq;
    pq.push({0, i});

    while(!pq.empty()) {
      auto[csht, cv] = pq.top(); pq.pop();

      if(csht != sht[i][cv]) {
        continue;
      }

      for(auto [dst, wei]: g[cv]) {
        if(sht[i][cv] + wei < sht[i][dst]) {
          sht[i][dst] = sht[i][cv] + wei;
          pq.push({sht[i][dst], dst});
        }
      }
    }
  }

  for(int i = 0; i < Q; i++) {
    cin >> q1 >> q2;

    cout << sht[q1][q2] << '\n';
  }

  return 0;
}
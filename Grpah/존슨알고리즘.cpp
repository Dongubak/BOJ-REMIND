#include <bits/stdc++.h>
#define pp pair<int, int>

using namespace std;

int V, E;

int main(void) {
  cin >> V >> E;
  vector<vector<pp>> G(V + 1);

  int src, dst, weight;

  for(int i = 0; i < E; i++) {
    cin >> src >> dst >> weight;
    G[src].emplace_back(dst, weight);
  }

  
  for(int i = 1; i <= V; i++) G[0].emplace_back(i, 0);
  
  /// Bellmanford
  vector<int> sht(V + 1, 1 << 30);
  sht[0] = 0;

  for(int i = 0; i < V; i++) { // V번 
    for(int cur = 0; cur <= V; cur++) {
      for(auto& edge: G[cur]) {
        auto& [dst, wei] = edge;
        if((sht[cur] != (1 << 30)) && sht[dst] > sht[cur] + wei) {
          sht[dst] = sht[cur] + wei;
        }
      }
    }
  }

  for(int cur = 0; cur <= V; cur++) {
    for(auto& edge: G[cur]) {
      auto& [dst, wei] = edge;
      if((sht[cur] != (1 << 30)) && sht[dst] > sht[cur] + wei) {
        cout << "음수 가중치 존재";
        return 0;
      }
    }
  }

  vector<vector<pp>> nG(V + 1);
  for(int cur = 1; cur <= V; cur++) {
    for(auto& [dst, wei]: G[cur]) {
      int nWei = wei + sht[cur] - sht[dst];
      nG[cur].emplace_back(dst, nWei);
    }
  }

  vector<int> dist(V + 1, 1 << 30);
  int start = 1;
  dist[start] = 0;

  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
  pq.emplace(0, start);

  while (!pq.empty()) {
    auto [shtv, cur] = pq.top(); pq.pop();
    if (shtv > dist[cur]) continue;

    for (auto& [dst, wei] : nG[cur]) {
        if (dist[dst] > dist[cur] + wei) {
            dist[dst] = dist[cur] + wei;
            pq.emplace(dist[dst], dst);
        }
    }
  }

  for(int i = 1; i <= V; i++) {
    cout << dist[i] + sht[i] - sht[start] << " ";
  }
  cout << "\n";

  return 0;
}
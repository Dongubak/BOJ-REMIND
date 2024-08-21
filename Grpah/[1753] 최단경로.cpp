#include <bits/stdc++.h>

using namespace std;

int V, E, st;
vector<vector<pair<int, int>>> g;

void dijkstra() {
   priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; /// 큐에 넣을 당시 sht값과 그 정점을 pair로 저장
   vector<int> sht(V + 1, INT_MAX); sht[st] = 0;
   pq.push({0, st});

   while(!pq.empty()) {
      pair<int, int> cur = pq.top(); pq.pop();
      auto& [prevsht, cv] = cur;

      if(prevsht != sht[cv]) continue; // 조사할 필요가 없음

      for(auto& [d, w]: g[cv])
         if(sht[d] > sht[cv] + w) pq.emplace(sht[cv] + w, d), sht[d] = sht[cv] + w;
   }

   for(int i = 1; i <= V; i++)
      if(sht[i] == INT_MAX) cout << "INF" << '\n';
      else cout << sht[i] << '\n';
}


int main(void) {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   cin >> V >> E >> st;
   int s, d, w;
   g.resize(V + 1, vector<pair<int, int>>()); // 1base index

   for(int i = 0; i < E; i++)
      cin >> s >> d >> w, g[s].emplace_back(d, w);

   dijkstra();
   
   // for(int i = 1; i <= V; i++)
   //    for(auto [d, w]: g[i])
   //       cout << i << " " << d << " " << w << '\n';

   return 0;
}
#include <bits/stdc++.h>

using namespace std;

int V, E, K;

vector<vector<pair<int, int>>> g;

void dijkstra(vector<vector<int>>& sht, int st) {
   priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
   pq.emplace(0, st); sht[st][st] = 0;

   while(!pq.empty()) {
      pair<int, int> cur = pq.top(); pq.pop();
      auto& [prevsht, cv] = cur;
      if(prevsht > sht[st][cv]) continue;

      for(auto& [d, w]: g[cv]) 
         if(sht[st][d] > sht[st][cv] + w) pq.emplace(sht[st][cv] + w, d), sht[st][d] = sht[st][cv] + w;
      
   }
}

void sol() {
   vector<vector<int>> sht(V + 1, vector<int>(V + 1, INT_MAX));
   for(int i = 1; i <= V; i++) {
      dijkstra(sht, i);
   }

   int m = -1;
   for(int i = 1; i <= V; i++)
      m = max(m, sht[i][K] + sht[K][i]);
   
   cout << m;
}

int main(void) {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   
   int s, d, w;

   cin >> V >> E >> K;
   g.resize(V + 1, vector<pair<int, int>>());

   for(int i = 0; i < E; i++)
      cin >> s >> d >> w, g[s].emplace_back(d, w);
   
   sol();

   return 0;
}
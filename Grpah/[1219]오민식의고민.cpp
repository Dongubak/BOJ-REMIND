#include <bits/stdc++.h>
using namespace std;

int V, E, st, dst;
vector<vector<pair<int, int>>> g;
vector<int> earn;


void minsika() {
   priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq; /// 큐에 넣을 당시 sht값과 그 정점을 pair로 저장
   vector<long long> sht(V, LLONG_MIN); sht[st] = 0LL;
   pq.push({0, st});

   while(!pq.empty()) {
      pair<long long, int> cur = pq.top(); pq.pop();
      auto& [prevsht, cv] = cur;

      if(prevsht != sht[cv]) continue; // 조사할 필요가 없음

      for(auto& [d, w]: g[cv])
         if(sht[d] < sht[cv] + w) pq.emplace(sht[cv] + w, d), sht[d] = sht[cv] + w;
   }

   if(sht[dst] == LLONG_MIN) {
      cout << "gg";
      return;
   }

   sht[st] = earn[st]; ///시작 도시에서 최초로 돈을 벎

   for(int _ = 0; _ < V - 1; _++) { /// V - 1번 진행
      for(int i = 0; i < V; i++) {
         if(sht[i] == LLONG_MIN) continue;
         for(auto& [d, w]: g[i]) 
            if(sht[d] < sht[i] + earn[d] + w) sht[d] = sht[i] + earn[d] + w;
      }
   }

   queue<int> q;

   for(int i = 0; i < V; i++) {
      bool isinv = false;
      if(sht[i] == LLONG_MIN) continue;
      for(auto& [d, w]: g[i]) 
         if(sht[d] < sht[i] + earn[d] + w) q.push(d);
   }

   vector<int> vis(V, 0);

   while(!q.empty()) {
      int cur = q.front(); q.pop();
      for(auto& [d, w]: g[cur]) 
         if(vis[d] == 0)
            q.emplace(d), vis[d] = 1;
   }

   if(vis[dst]) cout << "Gee";
   else cout << sht[dst];
}


int main(void) {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   cin >> V >> st >> dst >> E;
   int s, d, w;
   g.resize(V, vector<pair<int, int>>());
   earn.resize(V, 0);

   for(int i = 0; i < E; i++)
      cin >> s >> d >> w, g[s].emplace_back(d, -w);

   for(int i = 0; i < V; i++)
      cin >> earn[i];

   minsika();

   vector<vector<int>> A(10, vector<int>(8, 0));

   vector<vector<int>> B(10, vector<int>());

   vector<vector<vector<int>>> C(10, vector<vector<int>>(8, vector<int>(5)));

   return 0;
}
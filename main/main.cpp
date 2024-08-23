#include <bits/stdc++.h>
using namespace std;

int V, E, st, dst;
vector<vector<pair<int, int>>> g;
int sht[100 + 1][2];

void mins() {
   for(int i = 1; i <= V; i++) sht[i][0] = INT_MIN;
   sht[st][0] = 0;

   for(int _ = 0; _ < V - 1; _++) { /// V - 1번 진행
      for(int i = 1; i <= V; i++) {
         if(sht[i][0] == INT_MIN) continue;
         for(auto& [d, w]: g[i])
            if(sht[d][0] < sht[i][0] + w) sht[d][0] = sht[i][0] + w, sht[d][1] = i;
      }
   }

   queue<int> q;

   for(int i = 1; i <= V; i++) {
      if(sht[i][0] == INT_MIN) continue;
      for(auto& [d, w]: g[i]) 
         if(sht[d][0] < sht[i][0] + w) q.push(d);
   }


   vector<int> vis(V + 1, 0);

   while(!q.empty()) {
      int cur = q.front(); q.pop();
      for(auto& [d, w]: g[cur]) 
         if(vis[d] == 0)
            q.emplace(d), vis[d] = 1;
   }

   if(vis[dst]) {
      cout << -1;
      return;
   }

   vector<int> path;
   int cur = dst;
   while(cur != st) {
      path.push_back(cur);
      cur = sht[cur][1];
   }
   path.push_back(st);
   reverse(path.begin(), path.end());

   for(int i : path) cout << i << " ";

   // vector<int> vis(V + 1, 0);

   // while(!q.empty()) {
   //    int cur = q.front(); q.pop();
   //    for(auto& [d, w]: g[cur]) 
   //       if(vis[d] == 0)
   //          q.emplace(d), vis[d] = 1;
   // }

   // if(vis[dst]) cout << "-1";
   // else trace(dst, sht);
}


int main(void) {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   cin >> V >> E, st = 1, dst = V;

   int s, d, w;
   g.resize(V + 1, vector<pair<int, int>>());

   for(int i = 0; i < E; i++)
      cin >> s >> d >> w, g[s].emplace_back(d, w);

   mins();

   return 0;
}
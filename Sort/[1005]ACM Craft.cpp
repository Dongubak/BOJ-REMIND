#include <bits/stdc++.h>

using namespace std;

class Graph {
public:
vector<vector<int>> G;
Graph(int n) {
   G.resize(n);
}

void addEdge(int st, int dst) {
   G[st].push_back(dst);
}
};


int t, n, k, x, y, w;
int deg[1000 + 6];
int cost[1000 + 6];
int times[1000 + 6];

int main(void) {
ios_base::sync_with_stdio(false);
cin.tie(NULL);

   cin >> t;

   while(t--) {

      cin >> n >> k;
      Graph g(n);
      
      vector<int> res;

      for(int i = 0; i < n; i++) {
         cin >> cost[i];
      }

      memset(deg, 0, sizeof(deg));
      memset(times, 0, sizeof(times));

      for(int i = 0; i < k; i++) {
         cin >> x >> y;
         g.addEdge(x - 1, y - 1);
         deg[y - 1] += 1;
      }

      cin >> w;
      w -= 1;

      queue<int> q;

      for(int i = 0; i < n; i++) {
         if(!deg[i]) {
               q.push(i);
               times[i] = cost[i];
         }
      }
         

      while(!q.empty()) {
         int f = q.front(); q.pop();
         res.push_back(f);
         
         for(auto adj: g.G[f]) {
               deg[adj]--;
               times[adj] = max(times[adj], times[f] + cost[adj]);
               if(!deg[adj] && adj != w) q.push(adj);
         }
      }

      cout << times[w] << '\n';
   }

   return 0;
}
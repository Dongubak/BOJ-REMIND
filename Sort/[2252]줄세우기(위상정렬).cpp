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

int main(void) {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   
   int v, e, st, dst;
   cin >> v >> e;

   Graph g(v);

   vector<int> deg(v, 0), res;

   for(int i = 0; i < e; i++) {
      cin >> st >> dst;
      g.addEdge(st - 1, dst - 1);
      deg[dst - 1] += 1;
   }

   queue<int> q;

   for(int i = 0; i < v; i++) 
      if(!deg[i]) q.push(i);

   while(!q.empty()) {
      int f = q.front(); q.pop();
      res.push_back(f);
      
      for(auto adj: g.G[f]) {
         deg[adj]--;
         if(!deg[adj]) q.push(adj);
      }
   }

   for(auto r: res) 
      cout << r + 1 << " ";
   

   return 0;
}
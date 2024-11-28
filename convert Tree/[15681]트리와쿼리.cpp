#include <bits/stdc++.h>
using namespace std;

int n, r, q;
vector<vector<int>> g;
vector<int> sub;

int dfs(int cur, int par) {
   sub[cur] = 1;

   for (int next : g[cur]) {
      if (next == par) continue; // common level
      sub[cur] += dfs(next, cur);
   }
   
   return sub[cur];
}

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   cin >> n >> r >> q;
   g.resize(n + 1);
   sub.resize(n + 1);

   int u, v;
   
   for (int i = 0; i < n - 1; i++) {
      cin >> u >> v;
      g[u].push_back(v);
      g[v].push_back(u);
   }

   dfs(r, -1);

   int qr;

   for (int i = 0; i < q; i++) {
      cin >> qr;
      cout << sub[qr] << '\n';
   }

   return 0;
}
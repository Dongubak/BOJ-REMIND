#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pp pair<int, int>

using namespace std;

int V, E;

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int src, dst, wei;

  cin >> V >> E;

  vector<vector<pp>> G(V + 1, vector<pp>());

  for(int i = 0; i < E; i++) {
    cin >> src >> dst >> wei;

    G[src].push_back({dst, wei});
  }

  int cv = 2;

  for(auto[dst, wei]: G[cv]) {

  }

  for(auto ptr = G[cv].begin(); ptr != G[cv].end(); ptr++) {
    int dst = ptr->first;
    int wei = ptr->second;
  }
  
  return 0;
}
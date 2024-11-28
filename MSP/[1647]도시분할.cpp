#include <bits/stdc++.h>
#define ll long long
#define pp pair<int, int>
#define all(x) begin(x), end(x)
#define edge tuple<int, int, int>
using namespace std;

class dijs {
   public:
   vector<int> dij;

   dijs(int v) {
      dij.resize(v);
      for(int i = 0; i < v; i++) dij[i] = i;
   }

   int fF(int v) { /// find founder
      if(v == dij[v]) return v;
      return dij[v] = fF(dij[v]);
   }

   bool mer(int v1, int v2) { /// merge
      int f1 = fF(v1), f2 = fF(v2);
      if(f1 != f2) {
         dij[f1] = f2;
         return true;
      }
      return false;
   }
};


int main(void) {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   int v, e, i, j, w;
   cin >> v >> e;

   dijs gr(v);
   vector<edge> eli(e);

   for(int k = 0; k < e; k++) {
      cin >> i >> j >> w;
      --i, --j;
      eli[k] = {w, i, j};
   }

   sort(all(eli));

   int res = 0, m = -1;

   for(auto& [w, i, j]: eli)
      if(gr.mer(i, j)) res += w, m = max(m, w);

   cout << res - m;

   return 0;
}
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

   int mer(int v1, int v2) { /// merge
      int f1 = fF(v1), f2 = fF(v2);
      if(f1 != f2) {
         dij[f1] = f2;
         return false;
      }
      return v1;
   }
};


int main(void) {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   int n, c, a1, a2, m;
   cin >> n >> c;
   dijs gr(n + 1);

   for(int i = 0; i < c; i++) {
      cin >> a1 >> a2;
      if((m = gr.mer(a1 + 1, a2 + 1))) {
         cout << i + 1;
         return 0;
      }
   }

   cout << 0;

   return 0;
}
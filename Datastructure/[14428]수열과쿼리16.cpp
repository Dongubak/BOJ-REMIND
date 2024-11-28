#include <bits/stdc++.h>

#define ll long long
#define pp pair<ll, ll>

using namespace std;

pp segTree[4'000'000];
ll A[1'000'000 + 1];

int n, q;

pp initSegT(int l, int r, int n) {
   if (l == r) 
      return segTree[n] = {A[l], l};
   
   int m = (l + r) / 2;

   return segTree[n] = min(initSegT(l, m, 2 * n), initSegT(m + 1, r, 2 * n + 1));
}

void init(int N) {
   initSegT(1, N, 1);
}

pp querySegT(int l, int r, int nl, int nr, int n) {
   if (nr < l || nl > r) 
      return {LLONG_MAX, LLONG_MAX};
   

   if (nl >= l && nr <= r)
      return segTree[n];
   

   int m = (nl + nr) / 2;

   return min(querySegT(l, r, nl, m, 2 * n), querySegT(l, r, m + 1, nr, 2 * n + 1));
}

pp query(int l, int r) {
   return querySegT(l, r, 1, n, 1);
}

pp updateSegT(int i, ll v, int nl, int nr, int n) {
   if (i < nl || nr < i) {
      return segTree[n];
   }

   if (nl == nr) {
      return segTree[n] = {v, nl};
   }

   int m = (nl + nr) / 2;

   return segTree[n] = min(updateSegT(i, v, nl, m, 2 * n), updateSegT(i, v, m + 1, nr, 2 * n + 1));
}

void update(int i, ll v) {
   updateSegT(i, v, 1, n, 1);
}

int main(void) {
   std::ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   cin >> n;

   for (int i = 1; i <= n; i++) {
      cin >> A[i];
   }

   init(n);

   int q, i, j, k;
   cin >> q;

   for (int _ = 0; _ < q; _++) {
      cin >> i >> j >> k;

      if (i == 1)
         update(j, k);
      else {
         pp res = query(j, k);
         cout << res.second << '\n';
      }
   }

   return 0;
}
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main(void) {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   int n, c, X[200000 + 10];
   cin >> n >> c;
   for(int i = 0; i < n; i++) cin >> X[i];

   sort(X, X + n);

   ll l = 1, r = LLONG_MAX, res = -1;

   while(l <= r) {
      ll m = l + (r - l) / 2, p = 1;
      
      int last = X[0];

      for(int i = 1; i < n; i++)
         if(X[i] - last >= m) p++, last = X[i];
      
      if(p >= c) l = m + 1, res = m;
      else r = m - 1;
   }

   cout << res;

   return 0;
}
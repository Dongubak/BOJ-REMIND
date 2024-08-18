#include <bits/stdc++.h>
#define UND -1061109568

using namespace std;

int dp[31][31];

int comb(int n, int k) {
   if(n == k || k == 0 || n == 0) return 1;

   int& ret = dp[n][k];
   if(ret != UND) return ret;

   return ret = comb(n - 1, k - 1) + comb(n - 1, k);
}

int main(void) {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   memset(dp, 0xc0, sizeof(dp));
   int T, n, r;
   cin >> T;

   while(T--) {
      cin >> r >> n;
      cout << comb(n, r) << '\n';
   }

   return 0;
}
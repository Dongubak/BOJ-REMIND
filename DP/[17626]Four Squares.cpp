#include <bits/stdc++.h>

using namespace std;

int dp[50000 + 1];

int main(void) {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   int n, m;
   cin >> n;
   dp[0] = 1;

   for(int i = 1; i <= n; i++) {
      m = dp[i - 1] + 1;
      for(int j = 1; j * j <= i; j++)
         m = min(m, dp[i - j * j] + dp[j * j]);
      dp[i] = m;
   }

   cout << dp[n];

   return 0;
}
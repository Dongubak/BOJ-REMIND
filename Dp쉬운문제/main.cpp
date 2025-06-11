#include <bits/stdc++.h>

using namespace std;

int dp[5000 + 1];

int main(void) {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   
   int N;
   cin >> N;

   memset(dp, -1, sizeof(dp));

   dp[3] = 1;
   dp[5] = 1;

   for(int i = 6; i <= N; i++) {
      if(i - 3 >= 0 && dp[i - 3] != -1) {
         dp[i] = dp[i - 3] + 1;
      }

      if(i - 5 >= 0 && dp[i - 5] != -1) {
         dp[i] = dp[i - 5] + 1;
      }
   }

   cout << dp[N];

   return 0;
}
#include <bits/stdc++.h>
         if(sht[d][0] < sht[i][0] + w) q.push(d);

using namespace std;

int dp[1000 + 1];

int sol(int n, int p) {
   if(n <= 4) {
      return dp[n];
   }

   int& ret = dp[n];
   if(ret != -1) {
      return ret;
   }
   ret = sol(n - 1, p + 1) || sol(n - 3, p + 1) || 
   sol(n - 4, p + 1);
   
   if(p % 2 == 0) {
      return !ret;
   } else {
      return ret;
   }
}

int main(void) {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   memset(dp, -1, sizeof(dp));
   dp[1] = 1;
   dp[2] = 0;
   dp[3] = 1;
   dp[4] = 1;
   int n;
   cin >> n;

   if(sol(n, 1)) {
      cout << "SK";
   } else {
      cout << "CY";
   }

   return 0;
}
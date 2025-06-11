#include <bits/stdc++.h>

using namespace std;

int dp[1000 + 1];

int main(void) {
   int n;
   cin >> n;

   dp[1] = 0;
   dp[2] = 1;
   dp[3] = 0;
   dp[4] = 1;

   if(n <= 4) {
      if(dp[n] == 1) {
         cout << "SK";
      } else {
         cout << "CY";
      }
   } else {
      for(int i = 5; i <= n; i++) {
         dp[i] = !dp[i - 1] || !dp[i - 3];
      }


      if(dp[n] == 1) {
         cout << "SK";
      } else {
         cout << "CY";
      }
   }


   return 0;
}
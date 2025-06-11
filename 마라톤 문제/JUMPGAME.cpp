#include <bits/stdc++.h>

using namespace std;

int n;
int A[100][100], dp[100][100];

int main(void) {
   cin >> n;

   for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
         cin >> A[i][j];
      }
   }

   dp[n - 1][n - 1] = 1;

   for(int i = n - 1; i >= 0; i--) {
      for(int j = n - 1; j >= 0; j--) {
         if(i == n - 1 && j == n - 1) continue;

         int k = A[i][j];
         
         if(i + k < n && dp[i + k][j] != 0) {
            dp[i][j] += dp[i + k][j];
         }

         if(j + k < n && dp[i][j + k] != 0) {
            dp[i][j] += dp[i][j + k];
         }
      }
   }

   cout << dp[0][0];

   return 0;
}

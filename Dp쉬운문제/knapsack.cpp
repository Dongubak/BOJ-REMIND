#include <bits/stdc++.h>

using namespace std;

int dp[100 + 1][100000 + 1];
int W[100 + 1];
int V[100 + 1];

int main(void) {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   
   int N, K;
   cin >> N >> K;

   for(int i = 1; i <= N; i++) cin >> W[i] >> V[i];

   for(int i = 1; i <= N; i++) {
      for(int j = 1; j <= K; j++) {
         if(j - W[i] >= 0) dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - W[i]] + V[i]);
         else dp[i][j] = dp[i - 1][j];
      }
   }

   cout << dp[N][K];

   return 0;
}
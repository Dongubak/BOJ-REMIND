#include <iostream>
#include <cmath>
using namespace std;

int cost[1000 + 1][3];
int dp[1000 + 1][3];

int main(void) {
   int n;
   cin >> n;

   for(int i = 1 ; i <= n; i++) {
      cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
   }

   for(int i = 0; i < 3; i++) {
      dp[1][i] = cost[1][i];
   }

   for(int i = 2; i <= n; i++) {
      for(int j = 0; j < 3; j++) {} 
         // dp[i][j] = min(dp[i - 1][(j ^ 1) % 3], dp[i - 1][(j ^ 2) % 3]) + cost[i][j];
   }

   cout << min(min(dp[n][0], dp[n][1]), dp[n][2]);

   return 0;
}
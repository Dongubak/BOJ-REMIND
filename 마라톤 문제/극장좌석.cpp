#include <iostream>

using namespace std;

int main(void) {
   int n;
   cin >> n;

   int dp[1000 + 1];
   dp[0] = 0;
   dp[1] = 1;

   for(int i = 0; i < n - 1; i++) {
      dp[i + 2] = dp[i + 1] + dp[i];
   }

   return 0;
}
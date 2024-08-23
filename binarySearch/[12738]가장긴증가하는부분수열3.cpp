#include <bits/stdc++.h>
using namespace std;

int main(void) {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   vector<int> dp; /// size = 0
   int N, t;
   cin >> N;

   for(int i = 0; i < N; i++) {
      cin >> t;
      if(dp.size() == 0 || t > dp.back()) dp.push_back(t);
      else {
         int l = 0, r = dp.size() - 1;
         
         while(l < r) {
            int m = (l + r) / 2;
            if(t > dp[m]) l = m + 1;
            else r = m;
         }
         dp[l] = t;
      }
   }

   cout << dp.size();

   return 0;
}
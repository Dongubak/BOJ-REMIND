#include <bits/stdc++.h>

using namespace std;

int main(void) {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   
   int n;
   cin >> n;

   vector<int> nums(n + 1, 0);
   vector<int> cache(n + 1, 0);

   int gmax = 0;

   for(int i = 1; i <= n; i++) 
      cin >> nums[i];
   
   for(int i = 1; i <= n; i++) {
      int tmax = 0;
      for(int j = i - 1; j >= 0; j--) {
         if(nums[i] > nums[j]) 
            tmax = max(tmax, cache[j]);
      }
      cache[i] = tmax + 1;
      gmax = max(cache[i], gmax);
   }

   cout << gmax;

   return 0;
}
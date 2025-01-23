#include <bits/stdc++.h>

using namespace std;

int n, t;

int nums[20];

int main(void) {
   cin >> n;
   for(int i = 0; i < n; i++) cin >> nums[i];
   cin >> t;

   for(int mask = 0; mask < (1 << n); mask++) {
      int s = 0;
      for(int i = 0; i < n; i++) 
         if(mask & (1 << i)) s += nums[i];
      if(s == t) {
         cout << "true";
         return 0;
      }
   }

   cout << "false";

   return 0;
}
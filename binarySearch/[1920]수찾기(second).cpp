#include <bits/stdc++.h>

using namespace std;

int main(void) {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   
   int n, q, t;
   cin >> n;

   vector<int> nums(n);

   for(int i = 0; i < n; i++) 
      cin >> nums[i];
   
   sort(nums.begin(), nums.end());

   cin >> q;

   for(int i = 0; i < q; i++) {
      cin >> t;
      auto it = lower_bound(nums.begin(), nums.end(), t);
      if(it != nums.end() && *it == t)
         cout << 1 << '\n';
      else 
         cout << 0 << '\n';
   }


   return 0;
} 
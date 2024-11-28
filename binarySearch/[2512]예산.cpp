#include <bits/stdc++.h>

#define ll long long
using namespace std;

vector<int> nums;

int main(void) {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   int n; ll lim;
   cin >> n;

   nums.resize(n, 0);

   for(int i = 0; i < n; i++) {
      cin >> nums[i];
   }
   cin >> lim;

   ll l = 1;
   ll r = *max_element(nums.begin(), nums.end());

   while(l <= r) {
      ll m = (l + r) / 2, msum = 0;
      for(int i = 0; i < n; i++) {
         if(nums[i] > m) msum += m;
         else msum += nums[i];
      }

      if(msum <= lim) l = m + 1;
      else r = m - 1;
   }


   cout << r;

   return 0;
}
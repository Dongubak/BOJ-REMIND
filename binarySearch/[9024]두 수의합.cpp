#include <bits/stdc++.h>

#define all(x) begin(x), end(x)
#define ll long long

using namespace std;

int nums[1'000'000];
int res[1'000'000];

int main(void) {
   std::ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   int T, n, k, m;
   cin >> T;

   while (T--) {
      m = 0;
      cin >> n >> k;

      for (int i = 0; i < n; i++) cin >> nums[i];

      sort(nums, nums + n);

      for (int i = 0; i < n - 1; i++) {
         int target = k - nums[i];
         int it = lower_bound(nums + i + 1, nums + n, target) - nums;

         int l = INT_MAX, r = INT_MAX;

         if (it - 1 > i) l = nums[it - 1] + nums[i];

         if (it < n) r = nums[it] + nums[i];

         if (l != INT_MAX) res[m++] = abs(k - l);
         if (r != INT_MAX) res[m++] = abs(k - r);
      }

      sort(res, res + m);
      int min_diff = res[0];
      int count = upper_bound(res, res + m, min_diff) - res;
      
      cout << count << '\n';
   }

   return 0;
}
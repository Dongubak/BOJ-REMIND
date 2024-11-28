#include <bits/stdc++.h>
#define pp pair<int, int>

using namespace std;

int nums[2000];

int main(void) {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   int n, q;
   cin >> n;

   for (int i = 0; i < n; i++) cin >> nums[i];

   vector<vector<pp>> cache(n + 1, vector<pp>(2, pair<int, int>(-1, -1)));

   cin >> q;

   for (int k = 0; k < q; k++) {
      int i, j, ok = 1;
      cin >> i >> j;

      int l = i - 1, r = j - 1;

      auto& ret = cache[(i + j) / 2][(j - i + 1) % 2];

      if (ret != make_pair(-1, -1)) {
         int lil = ret.first - 1;
         int lir = ret.second - 1;

         if (lil <= l && lir >= r) {
            cout << 1 << '\n';
            continue;
         }

         if (lil <= l) l = lir + 1;
         if (lir >= r) r = lil - 1;
      }

      while (l < r) {
         if (nums[l++] != nums[r--]) {
            ok = 0;
            break;
         }
      }

      if (ok) {
         cout << 1 << '\n';
         ret = {i, j};
      } else {
         cout << 0 << '\n';
      }
   }

   return 0;
}
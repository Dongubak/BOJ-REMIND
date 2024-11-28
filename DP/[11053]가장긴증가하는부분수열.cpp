#include <bits/stdc++.h>
using namespace std;

int cache[1000 + 1];
int nums[1000 + 1];
int n;

int lis(int i) {
   int& ret = cache[i];
   if (ret != -1) return ret;

   int m = 1;
   for (int j = i + 1; j < n; j++)
      if (nums[j] > nums[i]) m = max(m, 1 + lis(j));

   return cache[i] = m;
}

int main() {
   cin >> n;
   memset(cache, -1, sizeof(cache));

   for (int i = 0; i < n; i++) cin >> nums[i];

   int res = 0;
   for (int i = 0; i < n; i++) res = max(res, lis(i));
   
   cout << res;

   return 0;
}
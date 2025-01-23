#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main(void) {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   int k, n, L[10000 + 10], tmpL = -1, tmax = -1;
   cin >> k >> n;
   
   for(int i = 0; i < k; i++) cin >> L[i];
   
   ll l = 1, r = LLONG_MAX;

   while(l <= r) {
      ll mid = l + (r - l) / 2, s = 0;

      for(int i = 0; i < k; i++) s += (L[i] / mid);
      
      if(s >= n) l = mid + 1, tmpL = mid;
      else r = mid - 1;
   }
   cout << tmpL;

   return 0;
}
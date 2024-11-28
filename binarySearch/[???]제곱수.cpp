#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main(void) {
   ll n;
   cin >> n;

   if(n == 0) {
      cout << 0;
      return 0;
   }

   ll l = 1, r = n;


   while(l <= r) {
      ll m = l + (r - l) / 2;

      if(m <= n / m) l = m + 1;
      else r = m - 1;
   }

   if(r * r == n) {
      cout << r;
   } else {
      cout << r + 1;
   }

   return 0;
}
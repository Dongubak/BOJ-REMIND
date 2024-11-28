#include <bits/stdc++.h>

using namespace std;

long long fac[101];

long long factorial(int n) {
   if(n == 1 || n == 0) return 1;
   long long& ret = fac[n];
   if(ret != -1) return ret;
   return ret = (factorial(n - 1) * n);
}

int main(void) {
   int n;
   cin >> n;

   bool odd = n % 2;

   memset(fac, -1, sizeof(fac));

   long long res = 0;

   for(int i = 0; i <= n; i++) {
      if(odd && !(i % 2)) continue;
      else if(!odd && (i % 2)) continue;

      int h = (n - i) / 2;
      int g = i;

      res += factorial(h + g) / (factorial(h) * factorial(g));
   }

   cout << res;

   return 0;
}
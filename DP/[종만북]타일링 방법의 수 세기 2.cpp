#include <bits/stdc++.h>

using namespace std;

int w[101];

int sol(int n) {
   if(n == 0 || n == 1) return 1;

   int& ret = w[n];
   if(ret != -1) return ret;

   return ret = sol(n - 1) + sol(n - 2);
}

int main(void) {
   int n;
   cin >> n;

   bool odd = n % 2;

   memset(w, -1, sizeof(w));

   cout << sol(n);

   return 0;
}
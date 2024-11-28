#include <bits/stdc++.h>

using namespace std;

int n;
int cost[1000][3];

int paint(int i, int l, int c, int r, int st) {
   if(c == l || c == r) return 1 << 30;

   cout << c << " -> ";
   if(i >= n - 1) {
      if(r != st) return 1 << 30;
      cout << '\n';
      return cost[n - 1][c];
   }
   
   // l c r
   return cost[i][c] + min(paint(i + 1, c, r, l, st), paint(i + 1, c, r, c, st));
}

int main(void) {
   cin >> n;

   for(int i = 0; i < n; i++) {
      for(int j = 0; j < 3; j++) cin >> cost[i][j];
   }

   int m = 1 << 30;

   for(int i = 0; i < 3; i++)
      for(int j = 0; j < 3; j++)
         for(int k = 0; k < 3; k++) {
            if(i != j && i != k) {
               cout << j << " " << i << " " << k << " ";
               int res = paint(0, j, i, k, i);
               cout << res << '\n';
               m = min(m, res);
            }
         }
            

   cout << m;

   return 0;
}
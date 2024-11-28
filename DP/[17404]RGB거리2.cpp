#include <bits/stdc++.h>
using namespace std;

int n;
int cost[1000][3];

int cache[1000][3][3];

int paint(int i, int l, int r) { /// l은 다음집, r은 이전집
   if (i == n - 1) {
      int res = 1 << 30;
      for (int color = 0; color < 3; color++) {
         if (color != r && color != l) {
            res = min(res, cost[i][color]);
         }
      }
      return res;
   }

   int& ret = cache[i][l][r];
   if(ret != -1) return ret;

   int res = 1 << 30;
   for (int j = 0; j < 3; j++) {
      if (j != r) { /// r은 이전집
         res = min(res, cost[i][j] + paint(i + 1, l, j));
      }
   }
   return ret = res;
}

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   cin >> n;

   memset(cache, -1, sizeof(cache));

   for (int i = 0; i < n; i++)
      for (int j = 0; j < 3; j++) cin >> cost[i][j];
   int m = 1 << 30;

   for (int l = 0; l < 3; l++) 
      m = min(m, cost[0][l] + paint(1, l, l));
   
   cout << m << endl;

   return 0;
}
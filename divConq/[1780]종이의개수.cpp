#include <bits/stdc++.h>
using namespace std;

int N;
vector<vector<int>> A;
int ans[3] {}; // init 0

int k;

int isValid(pair<int, int> cur, int a) {
   auto& [r, c] = cur;
   int u = A[r][c];
   for(int i = r; i < r + a; i++)
      for(int j = c; j < c + a; j++) if(A[i][j] != u) return 2;

   return u;
}

void divconq(pair<int, int> cur, int a) {
   auto& [r, c] = cur;
   
   if(a <= 1) {
      if(a == 1) ans[A[r][c] + 1] += 1;
      return;
   }

   int res = isValid(cur, a);
   if(res != 2) ans[res + 1] += 1;
   else 
      for(int i = 0; i < 3; i++)
         for(int j = 0; j < 3; j++)
            divconq({r + (i * a / 3), c + (j * a / 3)}, a / 3);
}

int main(void) {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   cin >> N;

   A.resize(N, vector<int>(N, 0));

   for(int i = 0; i < N; i++)
      for(int j = 0;j < N; j++)
         cin >> A[i][j];

   divconq({0, 0}, N);

   for(int i = 0; i < 3; i++) 
      cout << ans[i] << '\n';

   return 0;
}
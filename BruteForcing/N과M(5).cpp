#include <bits/stdc++.h>
#define all(x) begin(x), end(x)

using namespace std;

int n, m;
vector<int> A;
vector<int> vis;

void rec(int i, int k, vector<int> subset) {
   if(i >= n || k == m) {
      if(k == m) {
         for(auto a: subset) cout << a << " ";
         cout << '\n';
      }

      return;
   }

   for(int i = 0; i < n; i++) {
      if(!vis[i]) {
         subset.push_back(A[i]); vis[i] = 1;
         rec(i + 1, k + 1, subset);

         subset.pop_back(); vis[i] = 0;
         rec(i + 1, k, subset);
      }
   }
}

int main(void) {
   cin >> n >> m;

   A.resize(n, 0);

   for(int i = 0; i < n; i++) {
      cin >> A[i];
   }

   sort(all(A));

   return 0;
}
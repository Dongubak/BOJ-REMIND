#include <bits/stdc++.h>

using namespace std;

int main(void) {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   
   int ar, ac, br, bc;
   cin >> ar >> ac;

   vector<vector<int>> A(ar, vector<int>(ac));
   

   for(int i = 0; i < ar; i++)
      for(int j = 0; j < ac; j++) 
         cin >> A[i][j];

   cin >> br >> bc;

   vector<vector<int>> B(br, vector<int>(bc));

   vector<vector<int>> ans(ar, vector<int>(bc));

   for(int i = 0; i < br; i++)
      for(int j = 0; j < bc; j++)
         cin >> B[i][j];

   for(int i = 0; i < ar; i++) {
      for(int j = 0; j < bc; j++) {
         int res = 0;
         for(int k = 0; k < ac; k++) res += A[i][k] * B[k][j];
         ans[i][j] = res;
      }
   }

   for(auto r: ans) {
      for(auto c: r) {
         cout << c << ' ';
      }
      cout << '\n';
   }

   return 0;
}
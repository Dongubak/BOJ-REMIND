#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int MOD = 1'000'000'007;

vector<vector<long long>> mul(const vector<vector<long long>>& A, const vector<vector<long long>>& B) {
   int n = A.size();
   vector<vector<long long>> result(n, vector<long long>(n));

   for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
         for (int k = 0; k < n; k++) {
            result[i][j] = (result[i][j] + A[i][k] * B[k][j]) % MOD;
         }
      }
   }

   return result;
}

vector<vector<long long>> power(vector<vector<long long>> A, ll i) {
   if(i == 0) {
      vector<vector<long long>> res(A.size(), vector<long long>(A.size()));
      for(int i = 0; i < A.size(); i++) res[i][i] = 1;
      return res;
   }

   vector<vector<long long>> half = power(A, i / 2);
   half = mul(half, half);

   if(i % 2 != 0) { // 홀수면 A를 한번 곱해줘야함
      half = mul(half, A);
   }

   return half;
}

int main(void) {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   
   long long n;
   cin >> n;

   vector<vector<long long>> M(2, vector<long long>(2, 1));
   M[1][1] = 0;

   cout << power(M, n)[1][0];

   return 0;
}
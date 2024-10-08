#include <bits/stdc++.h>
#define ll long long
using namespace std;

int N;
ll B;
vector<vector<int>> A;
const int MOD = 1000;

vector<vector<int>> mul(const vector<vector<int>>& A, const vector<vector<int>>& B) {
   int n = A.size();
   vector<vector<int>> result(n, vector<int>(n));

   for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
         for (int k = 0; k < n; k++) {
            result[i][j] = (result[i][j] + A[i][k] * B[k][j]) % MOD;
         }
      }
   }

   return result;
}

vector<vector<int>> power(vector<vector<int>> A, ll i) {
   if(i == 0) {
      vector<vector<int>> res(A.size(), vector<int>(A.size()));
      for(int i = 0; i < A.size(); i++) res[i][i] = 1;
      return res;
   }

   vector<vector<int>> half = power(A, i / 2);
   half = mul(half, half);

   if(i % 2 != 0) { // 홀수면 A를 한번 곱해줘야함
      half = mul(half, A);
   }

   return half;
}

int main(void) {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   cin >> N >> B;
   vector<vector<int>> A(N, vector<int>(N));

   for(int i = 0; i < N; i++)
      for(int j = 0; j < N; j++)
         cin >> A[i][j];

   for(auto a: power(A, B)) {
      for(auto b: a) cout << b << " ";
      cout << '\n';
   }

   return 0;
}
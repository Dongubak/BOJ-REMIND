#include <bits/stdc++.h>
#define crr cerr

using namespace std;

int N, K;
int A[1024 + 1][1024 + 1];

int main(void) {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   cin >> N >> K;

   for(int i = 1; i <= N; i++) {
      for(int j = 1; j <= N; j++) {
         cin >> A[i][j];
         A[i][j] += A[i][j - 1];
      }
   }

   for(int i = 1; i <= N; i++) {
      for(int j = 1; j <= N; j++) {
         crr << A[i][j] << " ";
      }
      crr << '\n';
   }

   int r1, c1, r2, c2;

   for(int i = 0; i < K; i++) {
      cin >> r1 >> c1 >> r2 >> c2;

      int sum = 0;
      for(int r = r1; r <= r2; r++) {
         sum += A[r][c2] - A[r][c1 - 1];
      }

      cout << sum << '\n';
   }

   return 0;
}
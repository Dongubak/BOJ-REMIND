#include <bits/stdc++.h>

using namespace std;

int main(void) {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   
   int N;
   cin >> N;

   vector<int> A(N);
   vector<int> B(N);

   for(int i = 0; i < N; i++) cin >> A[i];

   for(int j = 0; j < N; j++) cin >> B[j];

   sort(A.begin(), A.end());
   sort(B.begin(), B.end());

   int i = 0; int j = N - 1;
   int res = 0;
   for(int i = 0; i < N; i++) {
      res += A[i] * B[j--];
   }

   cout << res;

   return 0;
}
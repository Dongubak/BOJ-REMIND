#include <bits/stdc++.h>

using namespace std;

int main(void) {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   int N, M, K, t;
   cin >> N >> M >> K;
   
   vector<vector<int>> A(N, vector<int>(2, 0));
   
   for(int i = 0; i < M; i++) {
      cin >> t;
      A[t][0] = 1;
   }

   int flag = 0;
   // for(int i = 0; i < N; i++) {
   //    cout << A[i][flag] << " ";
   // }
   // cout << '\n';
   while(K--) {
      for(int i = 0; i < N; i++) {
         if(A[i][flag] == 1) {
            if(i == 0) {
               A[N - 1][!flag] += 1;
               A[1][!flag] += 1;
            } else if(i == N - 1) {
               A[N - 2][!flag] += 1;
               A[0][!flag] += 1;
            } else {
               A[i - 1][!flag] += 1;
               A[i + 1][!flag] += 1;
            }
         } else if(A[i][flag] == 2)
            A[i][!flag] = 0;
         
         A[i][flag] = 0;
      }

      flag = !flag;
   }
   
   int count = 0;
   for(int i = 0; i < N; i++) {
      if(A[i][flag] == 1) {
         count++;
      }
   }

   cout << count;

   return 0;
}
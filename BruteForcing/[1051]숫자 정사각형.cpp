#include <bits/stdc++.h>
#define ll long long
#define crr cerr

using namespace std;

int main(void) {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   
   int N, M, t;
   cin >> N >> M; cin.get();

   vector<vector<int>> A(N, vector<int>(M, 0));

   for(int i = 0; i < N; i++) {
      for(int j = 0; j < M; j++) 
         t = cin.get(), A[i][j] = t - '0';
      cin.get();
   }

   int m = -1;

   for(int i = 0; i <= min(N, M); i++) /// i는 한변의 크기
      for(int j = 0; j < N; j++)
         for(int k = 0; k < M; k++)
            ///[j][k]에서의 한변이 i인 정사각형 조사
            if(k + i >= 0 && k + i < M && j + i >= 0 && j + i < N &&
               A[j][k] == A[j][k + i] && A[j + i][k] == A[j + i][k + i] && A[j][k] == A[j + i][k]
            ) m = max(m, (i + 1)* (i + 1));
 
   cout << m;

   return 0;
}
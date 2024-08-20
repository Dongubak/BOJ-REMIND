#include <bits/stdc++.h>

using namespace std;

int N, K;
vector<int> A;

int count = 0;

void gSum(int i, int sum, int n) { // i는 index n은 고른 것의 개수
   if(i >= N) {
      if(sum == K && n != 0) ++::count;
      return;
   }

   gSum(i + 1, sum + A[i], n + 1);
   gSum(i + 1, sum, n);
}

int main(void) {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   cin >> N >> K;
   A.resize(N, 0);

   for(int i = 0; i < N; i++) cin >> A[i];   
   gSum(0, 0, 0);
   cout << ::count;

   return 0;
}
#include <bits/stdc++.h>

using namespace std;

vector<int> A;
int N, M, t;

int main(void) {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   cin >> N;
   A.resize(N, 0);

   for(int i = 0; i < N; i++) 
      cin >> A[i];

   sort(A.begin(), A.end());
   
   cin >> M;
   
   for(int i = 0; i < M; i++) {
      cin >> t;

      int l = 0, r = N, f = false;
      while(l < r) {
         int m = (l + r) / 2;

         if(t > A[m]) l = m + 1;
         else if(t < A[m]) r = m;
         else {
            cout << 1 << '\n', f = true;
            break;
         }
      }

      if(!f) cout << 0 << '\n';
   }
      
   
   return 0;
}
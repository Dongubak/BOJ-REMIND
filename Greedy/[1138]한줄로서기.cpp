#include <bits/stdc++.h>
#define crr cerr

using namespace std;

int main(void) {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   int N;
   cin >> N;

   vector<int> A(N);
   vector<int> ans(N, 0);

   for(int i = 0; i < N; ++i) cin >> A[i];

   for(int i = 0; i < N; ++i) {
      int l = 0;
      int st = 0;


      for(int j = 0; j < N; j++) {
         if(ans[j] == 0) l++;
         if(l == A[i] + 1) {
            st = j;
            break;
         }
      }
      
      while(ans[st] != 0) st++;
      
      ans[st] = i + 1;
   }

   for(int i = 0; i < N; i++) {
      cout << ans[i] << " ";
   }

   return 0;
}
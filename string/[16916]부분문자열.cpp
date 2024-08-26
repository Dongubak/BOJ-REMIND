#include <bits/stdc++.h>

using namespace std;

string A, B;

int main(void) {
   ios_base::sync_with_stdio(false);
   cin.tie(0);

   cin >> A >> B;

   vector<int> f(B.size(), 0);

   int j = 0;

   for(int i = 1; i < B.size(); i++) {
      while(j > 0 && B[i] != B[j]) j = f[j - 1];
   
      if(B[i] == B[j]) j++;
      
      f[i] = j;
   }

   j = 0;
   
   for(int i = 0; i < A.size(); i++) {
      while(j > 0 && A[i] != B[j]) j = f[j - 1];
      
      if(A[i] == B[j]) j++;
      

      if(j == B.size()) {
         // 패턴 B를 찾은 경우
         cout << 1;
         return 0;
      }
   }

   // 패턴 B를 찾지 못한 경우
   cout << 0;

   return 0;
}
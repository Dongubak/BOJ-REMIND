#include <bits/stdc++.h>
#define crr cerr
using namespace std;

int main(void) {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   
   int N;
   cin >> N;

   if(N < 100) {
      cout << N;
   } else {
      int c = 99;
      for(int i = 100; i <= N; i++) {
         string str = to_string(i); /// 123
         int d = str[1] - str[0];

         bool isValid = true;

         for(int j = 0; j < str.size() - 1; j++) 
            if(str[j + 1] - str[j] != d) {
               isValid = false;
               break;
            }
         if(isValid) ++c;   
      }
      cout << c;
   }


   return 0;
}
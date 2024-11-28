#include <bits/stdc++.h>

using namespace std;

int n;
string str;

int getDiff(int st, int end) {
   if(str.substr(st, end - st + 1) == string(end - st + 1, str[st])) return 1;
   bool com = true; /// 등차수열인가
   bool rotate = true;
   int a = str[st + 1] - str[st]; // 공차
   for(int i = st + 1; i <= end; i++) {
      if(str[i] - str[i - 1] != a) com = false;
      if(i + 1 <= end && str[i - 1] != str[i + 1]) rotate = false;
   }

   if(com) {
      if(a == 1 || a == -1) return 2;
      else return 5;
   } else if(rotate) {
      return 4;
   } else {
      return 10;
   }
}

int sol(int i) {
   if(i >= str.size()) return 0;

   int m = 1 << 30;

   for(int j = 3; j <= 5; j++) {
      if(j <= str.size()) {
         m = min(m, getDiff(i, i + j - 1) + sol(i + j));
      }
   }

   return m;
}


int main(void) {
   cin >> n;

   for(int i = 0; i < n; i++) {
      cin >> str;

      cout << sol(0) << '\n';
   }

   return 0;
}
#include <bits/stdc++.h>
#define UND -1061109568

using namespace std;

vector<pair<int, int>> cache;

pair<int, int> add(pair<int, int> a, pair<int, int> b) {
   return {a.first + b.first, a.second + b.second};
}

pair<int, int> fib(int k) {
   if(k <= 1) {
      if(k == 0) return {1, 0};
      else if(k == 1) return {0, 1};
      else return {0, 0};
   }

   pair<int, int>& ret = cache[k];
   if(ret != make_pair(-1, -1)) return cache[k];

   return ret = add(fib(k - 1), fib(k - 2));
}

int main(void) {
   int T, t;
   cache.resize(41, pair<int, int>(-1, -1));

   cin >> T;
   



   while(T--) {
      cin >> t;
      pair<int, int> res = fib(t);
      auto& [z, o] = res;
      cout << z << " " << o << '\n';
   }

   return 0;
}
#include <bits/stdc++.h>

using namespace std;

int main(void) {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   
   int N;
   string t;
   cin >> N;

   vector<string> strs(N);
   for(int i = 0; i < N; i++)
      cin >> strs[i];
   
   
   sort(strs.begin(), strs.end(), [&](const string& s1, const string& s2) -> bool {
      if(s1.size() == s2.size()) {
         return s1 < s2;
      } else {
         return s1.size() < s2.size();
      }
   });
   string prev = "";
   for(auto s: strs) {
      if(prev == s) continue;
      else {
         cout << s << '\n';
         prev = s;
      }
   }

   return 0;
}
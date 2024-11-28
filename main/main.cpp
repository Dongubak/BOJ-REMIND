#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define pp pair<int, int>

using namespace std;


int cache[101][101];
string pat, tar;

bool match(int pi, int ti) {
   int &ret = cache[pi][ti];

   if(ret != -1) return ret;

   while(pi < pat.size() && ti < tar.size() &&
      ((pat[pi] == tar[ti]) || (pat[pi] == '?')) ) {
         pi++, ti++;
      }

   if(pi == pat.size()) return ret = (tar.size() == ti);

   if(pat[pi] == '*') {
      for(int j = 0; j <= tar.size() - ti; j++) {
         if(match(pi + 1, ti + j)) {
            return ret = 1;
         }
      }
   }

   return ret = 0;
}

int main(void) {
   int T;
   cin >> T;
   int n;

   while(T--) {
      cin >> pat >> n;
      vector<string> res;

      for(int i = 0; i < n; i++) {
         memset(cache, -1, sizeof(cache));
         cin >> tar;
         if(match(0, 0)) res.push_back(tar);
      }

      sort(all(res));

      for(auto str: res) {
         cout << str << '\n';
      }
   }

   return 0;
}
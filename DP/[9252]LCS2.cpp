#include <bits/stdc++.h>
#define pp pair<int, int>
#define all(x) begin(x), end(x)

using namespace std;

int main(void) {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   string a, b;
   cin >> a >> b;

   vector<vector<pp>> res(a.size() + 1, vector<pp>(b.size() + 1, pair<int, int>(0, 0)));

   for(int i = 0; i < a.size(); i++) {
      for(int j = 0; j < b.size(); j++) {
         if(a[i] == b[j]) res[i + 1][j + 1] = {res[i][j].first + 1, j};
         else res[i + 1][j + 1] = max(res[i + 1][j], res[i][j + 1]);
      }
   }
   
   int i = a.size(), j = b.size(); /// res는 i, j
   /// a, b는 i - 1, j - 1
   string result = "";
   while(i > 0 && j > 0) {
      if(a[i - 1] == b[j - 1]) {
         result.push_back(a[i - 1]);
         --i, --j;
      } else if(res[i - 1][j].first > res[i][j - 1].first) --i;
      else --j;
   }

   reverse(all(result));
   cout << res[a.size()][b.size()].first << '\n' << result;


   return 0;
}
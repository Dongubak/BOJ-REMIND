#include <bits/stdc++.h>

using namespace std;

int t, n, w;
/// w는 제한 부피
/// n은 물건 개수
string names[100];
int vol[100], need[100];
int cache[1000 + 1][100];

int pack(int cap, int i) {
   if(i >= n) return 0;

   int& ret = cache[cap][i];
   if(ret != -1) return ret;

   if(vol[i] > cap)
      return ret = pack(cap, i + 1);

   return ret = max(pack(cap, i + 1), pack(cap - vol[i], i + 1) + need[i]);
}

int main(void) {
   cin >> t;

   while(t--) {
      memset(cache, -1, sizeof(cache));
      cin >> n >> w;

      for(int i = 0; i < n; i++) {
         cin >> names[i] >> vol[i] >> need[i];
      }

      cout << pack(w, 0) << '\n';
   }

   return 0;
}
#include <bits/stdc++.h>

using namespace std;

int main(void) {
   int K, N, s, o, ms = INT_MAX, mo = INT_MAX;
   cin >> K >> N;

   for(int i = 0; i < N; i++) {
      cin >> s >> o;
      ms = min(s, ms), mo = min(o, mo);
   }

   int res = min(min(mo * K, (K / 6 + 1) * ms), (K / 6) * ms + (K % 6) * mo);
   
   cout << res;

   return 0;
}
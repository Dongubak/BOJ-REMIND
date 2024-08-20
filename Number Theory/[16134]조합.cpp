#include <bits/stdc++.h>
#define MOD 1'000'000'007
#define ll long long

using namespace std;

ll fastpower(ll a, ll b) {
   int ret;
   if(b == 0) return 1LL;
   if(b % 2 == 0) { /// 짝수인 경우
      ll ret = fastpower(a, b / 2);
      return (ret * ret) % MOD;
   } else {
      ll ret = fastpower(a, (b - 1) / 2);
      return (ret * ret) % MOD * a % MOD;
   }
}

int main(void) {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   
   int n, r;
   cin >> n >> r;

   ll t = 1, b = 1;

   for(int i = n; i > n - r; i--) t = (t * i) % MOD;
   for(int i = 1; i <= r; i++) b = (b * i) % MOD;

   // b^(M - 2) mod MOD를 구하면 됨
   ll inv = fastpower(b, MOD - 2);
   // for(int i = 0; i < MOD - 2; i++) {
   //    st = (st * b) % MOD;
   // }
   cout << (t * inv) % MOD;

   return 0;
}
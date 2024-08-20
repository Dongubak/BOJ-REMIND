#include <bits/stdc++.h>
#define ll long long
#define MOD 1'000'000'007

using namespace std;

ll fastpower(ll a, ll b) {
   int ret;
   if(b == 0) return 1LL;
   if(b % 2 == 0) return (((ret = fastpower(a, b / 2)) * ret) % MOD); /// 짝수인 경우
   else {
      return (((ret = fastpower(a, (b - 1) / 2)) * ret) % MOD) * a % MOD;
   }
}

int main(void) {
   int a, b;
   cin >> a >> b;

   cout << fastpower(a, b);

   return 0;
}
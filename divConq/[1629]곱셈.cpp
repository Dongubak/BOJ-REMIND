#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll A, B, C;

ll mul(ll i) {
   if(i == 0) return 1LL;
   
   if(i % 2 == 0) return mul(i / 2) % C * mul(i / 2) % C;
   else return mul((i - 1) / 2) % C * mul((i - 1) / 2) % C * A % C;  
}

int main(void) {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   cin >> A >> B >> C;
   cout << mul(B) % C;

   return 0;
}
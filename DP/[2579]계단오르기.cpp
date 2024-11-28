#include <bits/stdc++.h>
using namespace std;

int steps[301];
int cache[301];
int n;

int main() {
   cin >> n;

   for (int i = 1; i <= n; i++) {
      cin >> steps[i];
   }

   cache[1] = steps[1];
   cache[2] = steps[1] + steps[2];

   for (int i = 3; i <= n; i++) {
      cache[i] = max(
         cache[i - 2] + steps[i],
         cache[i - 3] + steps[i - 1] + steps[i]
      );
   }

   cout << cache[n] << "\n";

   return 0;
}
#include <bits/stdc++.h>

using namespace std;

void sol(const string& seed, int gen) {
   if(gen == 0) {
      cout << seed;
      return;
   }

   for(int i = 0; i < seed.size(); i++) {
      if(seed[i] == 'X')
         sol("X+YF", gen-1);
      else if(seed[i] == 'Y') 
         sol("FX-Y", gen - 1);
      else
         cout << seed[i];
   }
}

int main(void) {
   sol("FX", 10);

   return 0;
} 
#include <bits/stdc++.h>
#define crr cerr
using namespace std;

double getL(tuple<int, int, int>& A, tuple<int, int, int>& B) {
   auto& [x1, y1, r1] = A;
   auto& [x2, y2, r2] = B;

   return sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));
}

int main(void) {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   int T;
   cin >> T;

   tuple<int, int, int> A, B;
   auto& [x1, y1, r1] = A;
   auto& [x2, y2, r2] = B;

   while(T--) {
      cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

      double len = getL(A, B);

      if(len < r1 + r2) {
         if(A == B) cout << -1 << '\n';
         else if(x1 == x2 && y1 == y2 && r1 != r2) cout << 0 << '\n';
         else { ///두 점의 좌표는 다르며 반지름은 같을 수 있음
            if(r1 > r2) swap(r1, r2);
            if(len + r1 < r2) cout << 0 << '\n';
            else if(len + r1 == r2) cout << 1 << '\n';
            else cout << 2 << '\n';
         }
      } else if(len == r1 + r2) cout << 1 << '\n';
      else cout << 0 << '\n';
   }

   return 0;
}
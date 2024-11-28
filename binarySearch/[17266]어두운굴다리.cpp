#include <bits/stdc++.h>

using namespace std;

int main(void) {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   int N, M;
   cin >> N >> M;

   vector<int> nums(M, 0);

   for(int i = 0; i < M; i++)
      cin >> nums[i];
   
   int l = 0, r = N;

   while(l <= r) {
      int m = (l + r) / 2;
      int prev = 0;
      bool flag = true;
      for(int i = 0; i < M; i++) {
         if(nums[i] - m > prev) { /// 불가능
            flag = false;
            break;
         }
         prev = nums[i] + m;
      }
      if(flag && prev >= N) { /// 가능이면 줄여야 함
         // cout << "r 줄임" << '\n';
         r = m - 1;
      } else { /// 불가능이면 더 늘려야함
         // cout << "l 늘림" << '\n';
         l = m + 1;
      }
   }
   cout << l;

   return 0;
}
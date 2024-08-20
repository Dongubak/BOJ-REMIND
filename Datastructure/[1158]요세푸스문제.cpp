#include <bits/stdc++.h>
#define crr cerr
using namespace std;

int main(void) {
   int N, K;
   cin >> N >> K;

   vector<int> vis(N); // i번째 index는 i + 1의 방문 여부

   int cur = 0;
   int n = 0; /// 방문한 숫자의 개수
   
   cout << '<';
   while(n != N) {
      int tcur = cur, tn = 0; //tn은 한 사이클에서 방문한 횟수이며 K를 맞춰야함
      while(tn < K) {
         if(vis[tcur] == 0) tn++;
         if(tn == K) break;
         tcur = (tcur + 1) % N;
      }
      
      vis[tcur] = 1, n++;
      cur = tcur - 1;

      // if(tcur == 0) cur = N - 1;
      // else cur = tcur - 1;
      
   
      cout << tcur + 1;
      if(n == N) cout << '>';
      else cout << ", ";
      cur = (cur + 1) % N;
   }

   return 0;
}
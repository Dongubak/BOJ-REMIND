#include <bits/stdc++.h>
#define pp pair<int, int>
#define tt tuple<int, int, int>
using namespace std;

int N, M, K, t, d, sharkCount, sharkPriority[401][5][5];
tt sea[20][20];
tt currentSharkPos[401];
int changeDir[5] = {0, 1, 3, 4, 2};
int R[5] = {0, -1, 0, 1, 0};
int C[5] = {0, 0, 1, 0, -1};
void input();
void decScent();
bool isDead(int sharkNumber);
void toDead(int sharkNumber);
int move(int target, int sharkNumber);

int main(void) {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   input();
   // display();
   sharkCount = M;
   while(!(d == 1001 || sharkCount == 1)) {      
      for(int sharkNumber = 1; sharkNumber <= M; sharkNumber++) {
         if(isDead(sharkNumber)) continue;

         auto [zeroFind, ownFind] = make_pair(0, sharkNumber);
         int res = move(zeroFind, sharkNumber);
         
         switch(res) {
            case 0:
               break;
            case 1:
               continue;
            case 2:
               toDead(sharkNumber);
               continue;
         }

         res = move(ownFind, sharkNumber);

         switch(res) {
            case 0:
               toDead(sharkNumber);
               sharkCount--;
               break;
            case 1:
               continue;
            case 2:
               toDead(sharkNumber);
               sharkCount--;
               break;
         }
      }
      d++;
      decScent();
      // display();
   }
   if(d == 1001) {
      cout << -1;
   } else {
      cout << d;
   }

   return 0;
}
void input() {
   cin >> N >> M >> K;

   for(int i = 0; i < N; i++) {
      for(int j = 0; j < N; j++) {
         cin >> t;
         auto& [scentNumber, scentDuration, isBeforZero] = sea[i][j];
         if(t > 0) {
            auto& [row, col, dir] = currentSharkPos[t];

            scentNumber = t, scentDuration = K;
            row = i, col = j;
         } else {
            isBeforZero = 1;
         }
      }
   }

   for(int i = 1; i <= M; i++) {
      cin >> t;
      auto& [row, col, dir] = currentSharkPos[i];
      dir = changeDir[t];
   }

   for(int sharkNumber = 1; sharkNumber <= M; sharkNumber++) {
      // sharkPriority[401][5][5]
      for(int i = 1; i <= 4; i++) {
         for(int j = 1; j <= 4; j++) {
            cin >> t;
            sharkPriority[sharkNumber][changeDir[i]][j] = changeDir[t];
         }
      }
   }
}

void decScent() {
   for(int i = 0; i < N; i++) {
      for(int j = 0; j < N; j++) {
         auto& [scentNumber, scentDuration, isBeforZero] = sea[i][j];

         bool find = false;

         for(int k = 1; k <= M; k++) {
            auto& [r, c, _] = currentSharkPos[k];
            if(
               r != -1 && 
               r == i && c == j
            ) {
               find = true;
               isBeforZero = 0;
               break;
            }
         }

         if(find) continue;

         if(scentDuration >= 1) {
            scentDuration -= 1;
         }
         if(scentDuration == 0) {
            scentNumber = 0;
            isBeforZero = 1;
         }

         if(scentDuration != 0) {
            isBeforZero = 0;
         }
      }
   }
}

bool isDead(int sharkNumber) {
   auto& [row, col, dir] = currentSharkPos[sharkNumber];
   return row == -1;
}

void toDead(int sharkNumber) {
   auto& [row, col, dir] = currentSharkPos[sharkNumber];
   row = -1, col = -1, dir = -1;
   sharkCount--;
}

int move(int target, int sharkNumber) {
   auto& [cr, cc, cdir] = currentSharkPos[sharkNumber];

   for(int i = 1; i <= 4; i++) {
      int ndir = sharkPriority[sharkNumber][cdir][i];
      int nr = cr + R[ndir], nc = cc + C[ndir];
      auto& [scentNumber, scentDuration, isBeforZero] = sea[nr][nc];
      // auto& [scentNumber, scentDuration] = sea[i][j];
      if(
         nr >= 0 && nr < N && nc >= 0 && nc < N &&
         (scentNumber == target || (isBeforZero == 1 && scentDuration == K))
      ) {
         if(scentNumber == target) {
            scentNumber = sharkNumber;
            scentDuration = K;
            
            cr = nr, cc = nc, cdir = ndir;
            return 1;
         } else {
            return 2;
         }
      }
   }

   return 0;
}
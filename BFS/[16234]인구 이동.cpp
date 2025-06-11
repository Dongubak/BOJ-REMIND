#include <bits/stdc++.h>
#define pp pair<int, int>

using namespace std;

int N, L, R, A[50][50], B[50][50][2001], vis[50][50], label = 1, day = 1, SUM[2501], COUNT[2501];
int RR[4] = {0, 0, 1, -1}, CC[4] = {1, -1, 0, 0};
bool bfs(int r, int c) {
   bool isMovable = false;
   queue<pp> q;
   q.emplace(r, c);
   vis[r][c] = 1;

   while(!q.empty()) {
      auto& [cr, cc] = q.front(); q.pop();
      B[cr][cc][day] = label;
      SUM[label] += A[cr][cc];
      COUNT[label] += 1;

      for(int i = 0; i < 4; i++) {
         int nr = cr + RR[i], nc = cc + CC[i];
         if(nr >= 0 && nr < N && nc >= 0 && nc < N &&
            !vis[nr][nc] &&
            abs(A[nr][nc] - A[cr][cc]) >= L &&
            abs(A[nr][nc] - A[cr][cc]) <= R
         ) {
            if(isMovable == false) isMovable = true;
            vis[nr][nc] = 1;
            q.emplace(nr, nc);
         }
      }
   }

   return isMovable;
}

bool move() {
   bool isMove = false;
   memset(vis, 0, sizeof(vis));
   memset(SUM, 0, sizeof(SUM));
   memset(COUNT, 0, sizeof(COUNT));

   label = 1;

   for(int i = 0; i < N; i++) {
      for(int j = 0; j < N; j++) {
         if(!vis[i][j]) {
            vis[i][j] = 1;
            if(bfs(i, j) && !isMove) isMove = true;
            label++;
         }
      }
   }

   return isMove;
}

void change() {
   for(int i = 0; i < N; i++) {
      for(int j = 0; j < N; j++) {
         if(B[i][j][day] != 0) {
            A[i][j] = SUM[B[i][j][day]] / COUNT[B[i][j][day]];
         }
      }
   }
}

void sol() {
   int m = 1;
   while(move()) {
      m++;
      change();
      day++;
   }
   if(m == 1) {
      cout << 0;
   } else {
      cout << day - 1;
   }
};
void input();

int main(void) {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   input();
   sol();

   return 0;
}

void input() {
   cin >> N >> L >> R;
   for(int i = 0; i < N; i++) {
      for(int j = 0; j < N; j++) {
         cin >> A[i][j];
      }
   }
}
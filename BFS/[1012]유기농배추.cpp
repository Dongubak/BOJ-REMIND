#include <bits/stdc++.h>
#define UND -1061109568

using namespace std;

int M, N, n, r, c;
int A[50][50];
int vis[50][50];
int R[4] = {0, 0, 1, -1};
int C[4] = {1, -1, 0, 0};

void bfs(int i, int j) {
   vis[i][j] = 1;
   queue<pair<int, int>> q;
   q.emplace(i, j);

   while(!q.empty()) {
      auto [cr, cc] = q.front(); q.pop();

      for(int k = 0; k < 4; k++) {
         int nr = cr + R[k];
         int nc = cc + C[k];

         if(nr >= 0 && nr < N &&
            nc >= 0 && nc < M &&
            vis[nr][nc] == 0 &&
            A[nr][nc] == 1
         ) {
            q.emplace(nr, nc);
            vis[nr][nc] = 1;
         }
      }
   }
}

int cab() {
   int count = 0;
   for(int i = 0; i < N; i++) {
      for(int j = 0; j < M; j++) {
         if(vis[i][j] == 0 && A[i][j] == 1) {
            bfs(i, j);
            count++;
         }
      }
   }

   return count;
}

int main(void) {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   int T;
   cin >> T;

   while(T--) {
      cin >> M >> N >> n; // n은 배추 개수

      memset(A, 0, sizeof(A));
      memset(vis, 0, sizeof(vis));

      for(int i = 0; i < n; i++) {
         cin >> c >> r;
         A[r][c] = 1;
      }

      cout << cab() << '\n';
   }

   return 0;
}
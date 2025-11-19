#include <bits/stdc++.h>
#define  FIO ios_base::sync_with_stdio(false); \
cin.tie(NULL);
#define pp pair<int, int>
#define all(x) x.begin(), x.end()

using namespace std;

int T, C, R, K;

int cab[50][50];
int RR[4] = {1, -1, 0, 0};
int CC[4] = {0, 0, 1, -1};

int main(void) {
  FIO
  cin >> T;

  while(T--) {
    memset(cab, 0, sizeof(cab));
    int c, r, count = 0;
    cin >> C >> R >> K;

    for(int i = 0; i < K; i++) {
      cin >> c >> r;
      cab[r][c] = 1;
    }

    for(int i = 0; i < R; i++) {
      for(int j = 0; j < C; j++) {
        if(cab[i][j]) {
          count++;

          queue<pp> q;
          q.emplace(i, j);

          while(!q.empty()) {
            auto [cr, cc] = q.front(); q.pop();

            for(int i = 0; i < 4; i++) {
              int nr = cr + RR[i];
              int nc = cc + CC[i];

              if(
                nr >= 0 &&  nr < R &&
                nc >= 0 &&  nc < C &&
                cab[nr][nc]
              ) {
                cab[nr][nc] = 0;
                q.emplace(nr, nc);
              }
            }
          }
        }
      }
    }

    cout << count << '\n';
  }

  return 0;
}
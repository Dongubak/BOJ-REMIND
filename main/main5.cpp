#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define tt tuple<int, int, int, int, int>
#define pp pair<int, int>
#define fIO ios_base::sync_with_stdio(false); \
cin.tie(NULL);

using namespace std;

int T;

int RR[8] = {0, 0, 1, -1, 1, 1, -1, -1};
int CC[8] = {1, -1, 0, 0, 1, -1, 1, -1};

int main(void) {
  fIO
  cin >> T;

  while(T--) {
    int c, r, p, tc, tr, count = 0;
    cin >> c >> r >> p;

    vector<vector<int>> A(r, vector<int>(c, 0));
    vector<vector<int>> vis(r, vector<int>(c, 0));

    for(int i = 0; i < p; i++) {
      cin >> tc >> tr;
      A[tr][tc] = 1;
    }
    
    for(int i = 0; i < r; i++) {
      for(int j = 0; j < c; j++) {
        if(!vis[i][j] && A[i][j]) {
          count++;
          vis[i][j] = 1;

          queue<pp> q;
          q.emplace(i, j);

          while(!q.empty()) {
            auto& [cr, cc] = q.front(); q.pop();

            for(int i = 0; i < 4; i++) {
              int nr = cr + RR[i];
              int nc = cc + CC[i];

              if(
                nr >= 0 && nr < r &&
                nc >= 0 && nc < c &&
                vis[nr][nc] == 0 &&
                A[nr][nc] == 1
              ) {
                q.emplace(nr, nc);
                vis[nr][nc] = 1;
              }
            }
          }
        }
      }
    }

    cout << count << '\n';
  }

  return 0;
};
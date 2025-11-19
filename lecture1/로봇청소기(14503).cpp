#include <bits/stdc++.h>
#define  FIO ios_base::sync_with_stdio(false); \
cin.tie(NULL);
#define pp pair<int, int>
#define all(x) x.begin(), x.end()
#define tt tuple<int, int, int>

using namespace std;

int N, M;

int RR[4] = {-1, 0, 1, 0};
int CC[4] = {0, 1, 0, -1};

int main(void) {
  FIO
  int sr, sc, sd; /// row of starting ...

  int count = 0;

  cin >> N >> M;

  vector<vector<int>> MAP(N, vector<int>(M, 0));
  cin >> sr >> sc >> sd;

  for(int i = 0; i < N; i++)
    for(int j = 0; j < M; j++)
      cin >> MAP[i][j];

  tt cur = {sr, sc, sd};
  /// 1: wall, 2: cleaned, 0: mess
  while(1) {
    auto& [cr, cc, cd] = cur;
    
    if(MAP[cr][cc] == 0) {
      MAP[cr][cc] = 2;
      count++;
    }

    bool flag = false;

    tt next;
    int _nd = cd;
    for(int i = 0; i < 4; i++) { /// 4방향 조사
      _nd--;
      if(_nd < 0) _nd = 3;

      int _nr = cr + RR[_nd];
      int _nc = cc + CC[_nd];

      if(
        _nr >= 0 && _nr < N &&
        _nc >= 0 && _nc < M &&
        MAP[_nr][_nc] == 0
      ) {
        auto&[nr, nc, nd] = next;
        nr = _nr, nc = _nc, nd = _nd;

        flag = true;

        break;
      }
    }

    if(flag) cur = next;
    else {
      int _nr = cr + RR[(_nd + 2) % 4];
      int _nc = cc + CC[(_nd + 2) % 4];
      if(
        _nr >= 0 && _nr < N &&
        _nc >= 0 && _nc < M &&
        MAP[_nr][_nc] != 1
      ) {
        cr = _nr, cc = _nc;
      } else {
        cout << count;
        return 0;
      }
    }
  }

  return 0;
}
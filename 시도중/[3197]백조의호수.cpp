#include <bits/stdc++.h>
#define pp pair<int, int>
#define all(x) begin(x), end(x)

using namespace std;

int R, C;
char lake[1500][1500];
pp st;

int r[4] = {1, -1, 0, 0};
int c[4] = {0, 0, 1, -1};

vector<vector<int>> fvis;

bool find(pp prev) {
    queue<pp> q;
    /// 이거 재활용하라는 거임 방문하지 않은 .을 발견하면 L로 도착인가

    // q.emplace(st);
    // fvis[st.first][st.second] = 1;

    while(!q.empty()) {
        pp cur = q.front(); q.pop();



        auto& [cr, cc] = cur;
        
        for(int i = 0; i < 4; i++) {
            int nr = cr + r[i], nc = cc + c[i];
            
            if(nr >= 0 && nr < R && nc >= 0 && nc < C &&
                lake[nr][nc] == '.' && fvis[nr][nc] == 0) {
                fvis[nr][nc] = 1, q.emplace(nr, nc);
            }/// 이동가능

            if(nr >= 0 && nr < R && nc >= 0 && nc < C &&
                fvis[nr][nc] == 0 && lake[nr][nc] == 'L') {
                return true;
            }
        }
    }

    return false;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    bool flag = false;
    
    cin >> R >> C;

    fvis.resize(R, vector<int>(C, 0));
    cin.get();

    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            lake[i][j] = cin.get();
            if(lake[i][j] == 'L' && !flag) {
                flag = !flag;
                st.first = i, st.second = j;
            }
        }
        cin.get();
    }

    int day = 0;

    queue<pp> q1, q2;
    flag = true; /// true면 q1에서 뺌
    vector<vector<int>> vis(R, vector<int>(C, 0));

    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            if(lake[i][j] == '.') {
                for(int k = 0; k < 4; k++) {
                    int nr = i + r[k], nc = j + c[k];

                    if(nr >= 0 && nr < R && nc >= 0 && nc < C &&
                        lake[nr][nc] == 'X' && vis[nr][nc] == 0) 
                        vis[nr][nc] = 1, q1.emplace(nr, nc);
                }
            }
        }
    }

    pp mcur = st;


    while(!find(mcur)) {
        day++;
        if(flag) {
            while(!q1.empty()) {
                pp cur = q1.front();
                if(q2.empty()) mcur = cur; 
                q1.pop();

                lake[cur.first][cur.second] = '.';

                for(int i = 0; i < 4; i++) {
                    int nr = cur.first + r[i], nc = cur.second + c[i];

                    if(nr >= 0 && nr < R && nc >= 0 && nc < C &&
                        lake[nr][nc] == 'X' && vis[nr][nc] == 0) {
                        vis[nr][nc] = 1, q2.emplace(nr, nc);
                    }
                }
            }
        } else {
            while(!q2.empty()) {
                pp cur = q2.front();

                if(q2.empty()) mcur = cur; 
        
                q2.pop();

                lake[cur.first][cur.second] = '.';

                for(int i = 0; i < 4; i++) {
                    int nr = cur.first + r[i], nc = cur.second + c[i];

                    if(nr >= 0 && nr < R && nc >= 0 && nc < C &&
                        lake[nr][nc] == 'X' && vis[nr][nc] == 0) {
                        vis[nr][nc] = 1, q1.emplace(nr, nc);
                    }
                }
            }
        }
        flag = !flag;
    }


    cout << day;

    return 0;
}
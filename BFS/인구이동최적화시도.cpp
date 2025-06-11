#include <bits/stdc++.h>
#define pp pair<int, int>
using namespace std;

int N, L, R, A[50][50], vis[50][50];
int RR[4] = {0, 0, 1, -1}, CC[4] = {1, -1, 0, 0};
vector<pp> movedPos;

int bfs(int sr, int sc) {
    if(vis[sr][sc]) return -1;  // 이미 방문한 곳이면 스킵
    
    queue<pp> q;
    vis[sr][sc] = 1;
    q.emplace(sr, sc);
    movedPos.clear();  // BFS 시작할 때만 벡터 초기화
    movedPos.emplace_back(sr, sc);
    int sum = A[sr][sc];

    while(!q.empty()) {
        auto [cr, cc] = q.front(); q.pop();

        for(int i = 0; i < 4; i++) {
            int nr = cr + RR[i], nc = cc + CC[i];
            
            if(nr >= 0 && nr < N && nc >= 0 && nc < N && !vis[nr][nc]) {
                int diff = abs(A[cr][cc] - A[nr][nc]);
                if(diff >= L && diff <= R) {
                    vis[nr][nc] = 1;
                    q.emplace(nr, nc);
                    movedPos.emplace_back(nr, nc);
                    sum += A[nr][nc];
                }
            }
        }
    }

    return movedPos.size() == 1 ? -1 : sum / movedPos.size();
}

bool move() {
    memset(vis, 0, sizeof(vis));
    bool isMoved = false;
    int avg;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if((avg = bfs(i, j)) != -1) {
                isMoved = true;
                for(auto [r, c]: movedPos) A[r][c] = avg;
            }
        }
    }
    return isMoved;
}

int main() {
    cin >> N >> L >> R;
    for(int i = 0; i < N; i++) 
        for(int j = 0; j < N; j++) 
            cin >> A[i][j];
    
    int day = 0;
    while(move() && day < 2000) day++;  // 2000은 문제의 최대 제한
    
    cout << day;
    return 0;
}
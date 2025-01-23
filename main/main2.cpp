#include <string>
#include <vector>
#include <iostream>
#define pp pair<int, int>

using namespace std;

int r, c;
int rvis[4][4];
int bvis[4][4];
int gcnt = 1 << 30;

pp rnd, bend;

int R[4] = {-1, 0, 1, 0};
int C[4] = {0, 1, 0, -1};

void dfs(pp cred, pp cblue, int ccnt, vector<vector<int>>& maze) {
    
    auto& [rcr, rcc] = cred;
    auto& [bcr, bcc] = cblue;
    // cout << "DFS 호출: Red(" << rcr << ", " << rcc << "), Blue(" << bcr << ", " << bcc << "), Count: " << ccnt << endl;

    bool isRfin = (cred == rnd) ? true : false;
    bool isBfin = (cblue == bend) ? true : false;

    if(isRfin && isBfin) {
        gcnt = min(gcnt, ccnt);
        return;
    }

    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            int rnr = rcr + R[i], rnc = rcc + C[i], ncnt = ccnt + 1;
            int bnr = bcr + R[j], bnc = bcc + C[j];
            // cout << "Red 다음 위치: (" << rnr << ", " << rnc << "), Blue 다음 위치: (" << bnr << ", " << bnc << ")" << endl;

            if(!isRfin && !isBfin) { // 둘다 도착하지 않은 경우
                // 1. 범위 만족
                // 2. 벽이 아님
                // 3. 방문 하지 않았어야함
                // 4. 서로 같은 곳으로 이동하면 안됨
                // 5. 자리를 바꿔서는 안됨
                if(
                  rnr >= 0 && rnr < r && rnc >= 0 && rnc < c &&
                  bnr >= 0 && bnr < r && bnc >= 0 && bnc < c &&
                  maze[rnr][rnc] == 0 && maze[bnr][bnc] == 0 &&
                  rvis[rnr][rnc] == 0 && bvis[bnr][bnc] == 0 &&
                  !(rnr == bnr && rnc == bnc) &&
                  !(cred == make_pair(bnr, bnc) && cblue == make_pair(rnr, rnc))
                ) {
                  rvis[rnr][rnc] = 1;
                  bvis[bnr][bnc] = 1;
                  dfs(make_pair(rnr, rnc), make_pair(bnr, bnc), ncnt, maze);

                  rvis[rnr][rnc] = 0, bvis[bnr][bnc] = 0;
                }
            } else if(!isRfin) { /// R만 도착하지 않은 경우
                // 1. 범위 만족
                // 2. 방문 하지 않았어야하며
                // 3. 길이여야하고
                // 4. blue랑 겹치면 안되고

                if(
                    rnr >= 0 && rnr < r && rnc >= 0 && rnc < c &&
                    rvis[rnr][rnc] == 0 && maze[rnr][rnc] == 0 &&
                    make_pair(rnr, rcr) != cblue
                ) {
                    rvis[rnr][rnc] = 1;
                    dfs(make_pair(rnr, rnc), cblue, ncnt, maze);
                    rvis[rnr][rnc] = 0;
                }
            } else if(!isBfin){ /// B만 도착하지 않은 경우
                // 1. 범위 만족
                // 2. 방문 하지 않았어야하며
                // 3. 길이여야하고
                // 4. red랑 겹치면 안되고
                if(
                    bnr >= 0 && bnr < r && bnc >= 0 && bnc < c &&
                    bvis[bnr][bnc] == 0 && maze[bnr][bnc] == 0 &&
                    make_pair(bnr, bnc) != cred
                ) {
                    bvis[bnr][bnc] = 1;
                    dfs(cred, make_pair(bnr, bnc), ncnt, maze);
                    bvis[bnr][bnc] = 0;
                }
            }
        }
    }
}

int solution(vector<vector<int>> maze) {
    int answer = 0;
    r = maze.size(), c = maze[0].size();

    pp rst, bst; // 각각의 시작 좌표 저장했음;

    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            if(maze[i][j] == 3) rnd = {i, j};
            else if(maze[i][j] == 4) bend = {i, j};   
            else if(maze[i][j] == 1) rst = {i, j};
            else if(maze[i][j] == 2) bst = {i, j};

            if(maze[i][j] == 5) maze[i][j] = 1; /// 벽을 1으로 놓고 이동가능한 경로를 0로 놓음
            else maze[i][j] = 0;
        }
    }

    rvis[rst.first][rst.second] = 1;
    bvis[bst.first][bst.second] = 1;

    dfs(rst, bst, 0, maze);

    if(gcnt == (1 << 30)) {
        return 0;
    } else {
        return gcnt;
    }
}
#include <bits/stdc++.h>
#include <tuple>
#define tt3 tuple<int, int, int>
#define crr cerr

using namespace std;

int n, m, k;
tt3 sea[20][20]; /// sharknum is one base
tt3 curpos[401]; /// one base (direction, snum)
int pdir[401][5][5]; /// one base (shark num, direction)

int dr[5] = {0, -1, 1, 0, 0};
int dc[5] = {0, 0, 0, -1, 1};

void input();

int main(void) {
    input();

    int t = 0; /// global Time
    int shCount = m;

    while(t++ <= 1000 || m == 1) {
        for (int i = 1; i <= m; i++) {
            int shInx = i; /// to one base
            
            auto&[cr, cc, dir] = curpos[shInx]; /// dir은 현재 상어가 보는 곳
            if(cr == -1) continue;
            auto& [csnum, cscTime, cscNum] = sea[cr][cc];
            
            bool isZero = false;
            bool isNonZero = false;
            for(int j = 1; j <= 4; j++) {
                int invDir = pdir[shInx][dir][j]; /// 조사할 필요가 있는 방향

                int nr = cr + dr[invDir], nc = cc + dc[invDir];
                auto& [nsnum, nscTime, nscNum] = sea[nc][nc]; // scTime 냄새 지속시간, scNum 냄새 고유번호
                if(
                    nr >= 0 && nr < n && nc >= 0 && nc < n &&
                    nscNum == 0
                ) {
                    cout << nr << " " << nc << '\n';
                    isZero = true, csnum = 0; /// 현재 위치 제거
                    nsnum = shInx, nscTime = k, nscNum = shInx; /// 다음 위치 기록
                    break;
                }
            }

            if(!isZero) {
                for(int j = 1; j <= 4; j++) {
                    int invDir = pdir[shInx][dir][j]; /// 조사할 필요가 있는 방향

                    int nr = cr + dr[invDir], nc = cc + dc[invDir];
                    auto& [nsnum, nscTime, nscNum] = sea[nc][nc]; // scTime 냄새 지속시간, scNum 냄새 고유번호

                    if(
                        nr >= 0 && nr < n && nc >= 0 && nc < n &&
                        nscNum == shInx
                    ) {
                        isNonZero = true, csnum = 0; /// 현재 위치 제거
                        nsnum = shInx, nscTime = k, nscNum = shInx; /// 다음 위치 기록
                        /// curpos 업뎃 필요
                        break;
                    }
                }   
            }

            if(!isNonZero) { // 이동 못함
                int shInx = i; /// to one base
                csnum = 0; /// Kill
                m -= 1;
                auto&[a, b, c] = curpos[shInx];
                a = -1;
            }
        }
        /// 마지막에 냄새 1칸 다운
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                auto& [csnum, cscTime, cscNum] = sea[i][j];
                if(csnum == 0 && cscTime > 0) cscTime -= 1;
                if(cscTime == 0) cscNum = 0;

                cout << csnum << " ";
            }
            cout << '\n';
        }
        cout << '\n';
    }

    if(t == 1002) {
        cout << -1;
    } else {
        cout << t;
    }

    return 0;
}

void input() {
    cin >> n >> m >> k;
    int t;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            auto& [snum, scTime, scNum] = sea[i][j];
            cin >> t;
            if(t > 0) {
                scTime = k;
                snum = scNum = t;

                auto&[cr, cc, dir] = curpos[snum];
                cr = i, cc = j;
            } else {
                snum = scTime = scNum = 0;
            }

            cout << snum << " ";
        }
        cout << '\n';
    }
    cout << '\n';

    /// input current sharks dir
    for(int i = 1; i <= m; i++) {
        auto&[_, __, dir] = curpos[i + 1];
        cin >> dir;
    }

    /// input dir's priority 
    for(int i = 0; i < m; i++) 
        for(int j = 0; j < 4; j++) 
            for(int k = 0; k < 4; k++)
                cin >> pdir[i + 1][j + 1][k + 1];
}
#include <bits/stdc++.h>
#define pp pair<int, int>

using namespace std;

string m[5]; // 입력받은 5x5 격자
int cnt = 0; // 조건을 만족하는 경우의 수
int R[4] = {0, 0, 1, -1}; // 상하좌우 이동 방향
int C[4] = {1, -1, 0, 0};
int t[25]; // 선택된 칸을 나타냄 (1이면 선택된 칸, 0이면 미선택)

// 재귀적으로 7개의 칸을 선택하는 함수
void rec(int idx, int s, int n) {
    // 종료 조건: 7개의 칸을 선택한 경우
    if (n == 7) {
        // 조건: 'S'의 개수가 4개 이상이어야 함
        if (s < 4) return;

        // 선택된 칸 중 첫 번째를 시작점으로 설정하여 연결성 검사
        int sidx = find(t, t + 25, 1) - t;

        queue<pp> q;
        vector<vector<int>> tvis(5, vector<int>(5, 0)); // 방문 체크용 2차원 배열
        q.emplace(sidx / 5, sidx % 5);
        tvis[sidx / 5][sidx % 5] = 1;

        int tcnt = 1; // 연결된 칸의 개수

        // BFS 탐색을 통해 7개의 칸이 연결되어 있는지 확인
        while (!q.empty()) {
            auto [cr, cc] = q.front(); q.pop();

            for (int i = 0; i < 4; i++) {
                int nr = cr + R[i], nc = cc + C[i];
                int nidx = nr * 5 + nc;

                if (nr >= 0 && nr < 5 && nc >= 0 && nc < 5 &&
                    !tvis[nr][nc] && t[nidx]) {
                    q.emplace(nr, nc);
                    tvis[nr][nc] = 1;
                    tcnt++;
                }
            }
        }

        // 모든 선택된 칸이 연결된 경우 카운트 증가
        if (tcnt == 7) cnt++;
        return;
    }

    // 재귀 호출 종료 조건: 인덱스가 25를 넘는 경우
    if (idx == 25) return;

    t[idx] = 1;
    rec(idx + 1, 
        s + (m[idx / 5][idx % 5] == 'S' ? 1 : 0), 
        n + 1
    );
    
    t[idx] = 0;
    rec(idx + 1, s, n);
    /// 마지막에 해제해줘야 이전 노드에서 다른 노드로 뻗어나갈 때 영향을 미치지 않음
}

int main(void) {
    // 입력 받기
    for (int i = 0; i < 5; i++) 
        cin >> m[i];
    
    // 재귀 호출 시작
    rec(0, 0, 0);

    // 결과 출력
    cout << cnt;

    return 0;
}
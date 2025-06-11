//
// Created by 김혁중 on 2025. 2. 15..
//
#include <iostream>
#include <algorithm>
#define all(x) x.begin(), x.end()

using namespace std;

void input(int &n, int& m, vector<int>& N, vector<int>& M) {
    int tNx = -1, tMx = -1;
    cin >> n;
    N.resize(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> N[i];
        tNx = max(tNx, N[i]);
    }

    cin >> m;
    M.resize(m, 0);
    for (int i = 0; i < m; i++) {
        cin >> M[i];
        tMx = max(tMx, M[i]);
    }

    if (tNx < tMx) {
        cout << -1;
        exit(0);
    }
}

int sol(int& n, int &m, vector<int>& N, vector<int>& M, vector<int>& C) {
    sort(all(N));
    sort(all(M));

    vector<int> D(N.size(), 0);

    int ni = 0, tsum = 0, ci = 0;

    for (int mi = 0; mi < m; mi++) {
        if (N[ni] >= M[mi]) {
            tsum += 1;
        } else {
            C[ci] = tsum;

            while (N[ni] < M[mi]) {
                ni++;
                ci++;
            }/// N[ni] >= M[mi]인 ni를 찾음
            tsum = 1;
        }
    }
    if (tsum != 0) C[ci] = tsum;

    reverse(C.begin(), C.end());
    int tmax = C[0];

    for (int i = 0; i < N.size() - 1; i++) {
        C[i + 1] += C[i];

        if (tmax < C[i + 1]) {
            const int q = (C[i + 1] / (i + 2));
            const int r = (C[i + 1] % (i + 2));

            if (q > tmax || (q == tmax && r != 0)) {
                if (r == 0) {
                    tmax = q;
                } else {
                    tmax = q + 1;
                }
            }
        }
    }

    return tmax;
}

int main(void) {
    int n, m;
    vector<int> N, M, C;
    input(n, m, N, M);

    C.resize(n, 0);

    cout << sol(n, m, N, M, C);

    return 0;
}
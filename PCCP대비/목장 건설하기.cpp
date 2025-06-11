//
// Created by 김혁중 on 2025. 2. 15..
//
#include <iostream>
#include <vector>

using namespace std;

bool input(const int& n, const int& m, vector<vector<int>>& A) {
    bool flag = false;
    int t;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> t;
            if (!flag && t == 0) flag = true;
            A[i][j] = t;
        }
    }

    return flag;
}

int sol(const int& n, const int & m, vector<vector<int>>& A, vector<vector<vector<int>>>& dp) {
    /// initial prefix sum
    for (int i = 0; i < n; i++) {
        int j = 0;

        while (j < m) {
            if (A[i][j] == 0) {
                if (j == 0) {
                    dp[i][0][0] = 1;
                } else {
                    dp[i][j][0] = dp[i][j - 1][0] + 1;
                }
            } else { /// A[i][j] is tree or stone
                int k = j + 1;
                while (k < m && A[i][k] != 0) {
                    k++;
                }
                if (k < m) dp[i][k][0] = 1;
                j = k;
            }
            j++;
        }
    }

    for (int j = 0; j < m; j++) {
        int i = 0;

        while (i < n) {
            if (A[i][j] == 0) {
                if (i == 0) {
                    dp[0][j][1] = 1;
                } else {
                    dp[i][j][1] = dp[i - 1][j][1] + 1;
                }
            } else { /// A[i][j] is tree or stone
                int k = i + 1;
                while (k < n && A[k][j] != 0) {
                    k++;
                }
                if (k < n) dp[k][j][1] = 1;
                i = k;
            }
            i++;
        }
    }

    int i = 0;
    int l = 2;

    while (i + l - 1 < n) {
        int j = 0;

        while (j + l - 1 < m) {
            bool flag = true;

            while (flag && i + l - 1 < n && j + l - 1 < m) {
                for (int k = 0; k < l; k++) { /// l번 반복;
                    if (dp[i + k][j + l - 1][0] < l || dp[i + l - 1][j + k][1] < l) {
                        flag = false;
                        break;
                    }
                }
                if (flag) l++;
            }
            j++;
        }
        i++;
    }

    return l - 1;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    bool zeroFlag = false;

    vector<vector<int>> A(n, vector<int>(m, 0));
    vector<vector<vector<int>>> dp(n, vector<vector<int>> (m, vector<int> (2, 0)));
    zeroFlag = input(n, m, A);

    if (!zeroFlag) {
        cout << 0;
        return 0;
    }

    cout << sol(n, m, A, dp);


    return 0;
}
#include <bits/stdc++.h>

using namespace std;

int N, M;
int m[101], c[101];

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  cin >> N >> M;

  int sum_m = 0;
  int sum_c = 0;

  for(int i = 1; i <= N; i++) {
    cin >> m[i];
    sum_m += m[i];
  }

  for(int i = 1; i <= N; i++) {
    cin >> c[i];
    sum_c += c[i];
  }

  int j_lim = sum_m - M;

  vector<vector<int>> dp(N + 1, vector<int>(j_lim + 1, 0));

  for(int i = 1; i <= N; i++) {
    for(int j = 0; j <= j_lim; j++) {
      if(j - m[i] >= 0) {
        dp[i][j] = max(
          dp[i - 1][j], dp[i - 1][j - m[i]] + c[i]
        );
      } else {
        dp[i][j] = dp[i - 1][j];
      }
    }
  }

  // for(int i = 0; i <= j_lim; i++) {
  //   cout << dp[N][i] << " ";
  // }
  // cout << "sum_c : " << sum_c << '\n';
  cout << sum_c - dp[N][j_lim];

  return 0;
}
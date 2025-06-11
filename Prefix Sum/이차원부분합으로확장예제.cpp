#include <bits/stdc++.h>

using namespace std;

int gridSum(const vector<vector<int>>& pSum, int r1, int c1, int r2, int c2) {
  int ret = pSum[r2][c2];
  if(r1 > 0) ret -= pSum[r1 - 1][c2];
  if(c1 > 0) ret -= pSum[r2][c1 - 1];
  if(r1 > 0 && c1 > 0) ret += pSum[r1 - 1][c1 - 1];

  return ret;
}

vector<vector<int>> getPsum(vector<vector<int>>& grid, int n, int m) {
  vector<vector<int>> pSum(n, vector<int>(m, 0));

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      pSum[i][j] = grid[i][j];
      if(i > 0) pSum[i][j] += pSum[i - 1][j];
      if(j > 0) pSum[i][j] += pSum[i][j - 1];
      if(i > 0 && j > 0) pSum[i][j] -= pSum[i - 1][j - 1];
    }
  }

  return pSum;
}

int main(void) {
  int n, m, k;
  cin >> n >> m;

  vector<vector<int>> nums(n, vector<int>(m, 0));
  vector<vector<int>> pSum;

  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
      cin >> nums[i][j];

  pSum = getPsum(nums, n, m);

  cin >> k;

  int r1, c1, r2, c2;

  for(int i = 0; i < k; i++){ 
    cin >> r1 >> c1 >> r2 >> c2;

    cout << gridSum(pSum, r1, c1, r2, c2) << '\n';
  }

  return 0;
}
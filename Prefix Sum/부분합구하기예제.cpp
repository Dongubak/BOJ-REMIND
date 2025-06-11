#include <bits/stdc++.h>
using namespace std;

vector<int> partialSum(const vector<int>& a) {
  vector<int> ret(a.size());
  ret[0] = a[0];

  for(int i = 1; i < a.size(); i++) {
    ret[i] = ret[i - 1] + a[i];
  }

  return ret;
}

int rangeSum(const vector<int>& psum, int a, int b) {
  if(a == 0) return psum[b];
  return psum[b] - psum[a - 1];
}

int main(void) {
  int n, k, from, to;
  cin >> n;

  vector<int> nums(n);

  for(int i = 0; i < n; i++) {
    cin >> nums[i];
  }

  vector<int> psum = partialSum(nums);

  cin >> k;

  for(int i = 0; i < k; i++) {
    cin >> from >> to;
    cout << rangeSum(psum, from - 1, to - 1) << '\n';
  }

  return 0;
}
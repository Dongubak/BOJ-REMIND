#include <bits/stdc++.h>

using namespace std;

vector<int> getp2Sum(vector<int>& nums) {
  vector<int> ret(nums.size());
  ret[0] = nums[0];

  for(int i = 1; i < nums.size(); i++) 
    ret[i] = ret[i - 1] + nums[i] * nums[i];
  
  return ret;
}

int getPartial2Sum(vector<int>& p2Sum, int a, int b) {
  return p2Sum[b] - p2Sum[a - 1];
}

vector<int> getpSum(vector<int>& nums) {
  vector<int> ret(nums.size());
  ret[0] = nums[0];

  for(int i = 1; i < nums.size(); i++) 
    ret[i] = ret[i - 1] + nums[i];
  
  return ret;
}

int getPartialSum(vector<int>& pSum, int a, int b) {
  return pSum[b] - pSum[a - 1];
}

double getPartialAverage(vector<int>& pSum, int a, int b) {
  return ((double)pSum[b] - (double)pSum[a - 1]) / (double)(b - a + 1);
}

double getVariance(vector<int>& p2Sum, vector<int>& pSum, int a, int b) {
  int mean = getPartialAverage(pSum, a, b);

  double ret = getPartial2Sum(p2Sum, a, b) - 2.0 * (double)mean * getPartialSum(pSum, a, b) + (b - a + 1) * mean * mean;

  return ret / (double)(b - a + 1);
}

int main(void) {
  int n, k, a, b;
  cin >> n;

  vector<int> nums(n);

  for(int i = 0; i < n; i++)
    cin >> nums[i];
  
  vector<int> p2Sum, pSum;

  p2Sum = getp2Sum(nums);
  pSum = getpSum(nums);

  cin >> k;

  for(int i = 0; i < k; i++) {
    cin >> a >> b;
    a -= 1, b -= 1;

    cout << getVariance(p2Sum, pSum, a, b) << '\n';
  }

  return 0;
}
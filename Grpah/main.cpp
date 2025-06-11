#include <bits/stdc++.h>

using namespace std;

int nums[1000 + 1];

int main(void) {
  int n;
  cin >> n;

  memset(nums, 0, sizeof(nums));

  for(int i = 1; i <= 1000; i++) { /// 1000 reps
    // 0인 경우 -1인 경우
    
    if(nums[i] > 0) {
      int i1 = 2 * i, i2 = i - 1;
      if(i1 <= 1000) {
        nums[i1] = 2 * nums[i];
      }

      nums[i2] = nums[i] - 1;
    }
  }

  return 0;
}
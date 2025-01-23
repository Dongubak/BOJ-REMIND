#include <bits/stdc++.h>
#define LIM 4000006
using namespace std;

int era[LIM];
vector<int> nums;

int main(void) {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);


   int n;
   cin >> n;

   nums.push_back(0);

   for(int i = 2; i <= n; i++) {
      if(era[i] == 0) 
         nums.push_back(i);
      for(int j = 2; j * i <= n; j++)
         era[i * j] = 1;
   }   

   for(int i = 1; i < nums.size(); i++) {
      nums[i + 1] = nums[i] + nums[i + 1];
   }

   int l = 0, r = 0;

   int count = 0;

   while(r < nums.size()) {
      if(nums[r] - nums[l] == n) {
         count++;
         r++;
      } else if(nums[r] - nums[l] < n) {
         r++;
      } else {
         l++;
      }
   }

   cout << count;

   return 0;
}
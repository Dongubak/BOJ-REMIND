#include <bits/stdc++.h>
#define ll long long
#define pp pair<int, int>
#define all(x) begin(x), end(x)

using namespace std;

ll nums[2000];

int main(void) {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   ll n;
   cin >> n;

   for(int i = 0; i < n; i++) 
      cin >> nums[i];
   
   sort(nums, nums + n);

   int count = 0;

   for(int i = 0; i < n; i++) {
      int t = i; /// target number's index
      int l = 0, r = n - 1; /// two pointer
      
      while(l < r) {
         if(l == t || r == t) {
            if(l == t) l++;
            else r--;
            
            continue;
         }
         if(nums[l] + nums[r] < nums[t]) {
            l++;
         } else if(nums[l] + nums[r] == nums[t]) {
            count++;
            break;
         } else {
            r--;
         }
      }
   }

   cout << count;
   

   return 0;
}
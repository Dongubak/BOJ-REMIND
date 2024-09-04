#include <bits/stdc++.h>
#define ll long long
#define all(x) begin(x), end(x)

using namespace std;

int A[100000], B[100000];

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n, t, i = 0, j = 0;
  cin >> n;
  
  
  for(int k = 0; k < n; k++) {
    cin >> t;
    if(t < 0) A[i++] = t;
    else B[j++] = t;
  }
  
  
  
  return 0;
}
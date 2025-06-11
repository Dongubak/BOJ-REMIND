#include <bits/stdc++.h>
#define ll long long
#define MOD 20091101
using namespace std;

int D[100000 + 1];
int psum[100000 + 1];
int cnt[100000 + 1];

int getClosestCommonMod(int i) {
  if(i <= 0) return -1;

  int findMod = psum[i];
  int j;
  for(int j = i - 1; j >= 0; j--) {
    if(psum[j] == findMod) {
      return j;
    }
  }
  return -1;
}

int maxBuy(int n) { /// n은 psum입장에서의 인덱스
  if(n == 0) { return 0; }
  int j = getClosestCommonMod(n);

  int notTake = maxBuy(n - 1);
  int take = 0;

  if(j != -1) {
    take = (j - 1 >= 0) ? maxBuy(j - 1) + 1 : 1;
  }
  return max(take, notTake);
}

int main(void) {
  int T;
  cin >> T;

  while(T--) {
    int n, k;
    cin >> n >> k;

    memset(cnt, 0, sizeof(cnt));

    for(int i = 0; i < n; i++) {
      cin >> D[i];
    }

    psum[0] = 0;
    for(int i = 1; i <= n; i++) {
      psum[i] = (psum[i - 1] + D[i - 1]) % k;
    }

    for(int i = 0; i <= n; i++) {
      cnt[psum[i]]++;
    }

    ll sum = 0;

    for(int i = 0; i < k; i++) {
      if(cnt[i] >= 2) {
        sum = (sum + ((cnt[i] * (cnt[i] - 1)) / 2) % MOD);
      }
    }

    cout << sum << " ";
    cout << maxBuy(n) << '\n';
    cout << '\n';
  }

  return 0;
}
#include <bits/stdc++.h>
#define ll long long
#define all(x) begin(x), end(x)
#define WBUF_SIZE (1 << 20)

using namespace std;

char rbuf[WBUF_SIZE];
int ridx, nidx;

inline char read() {
	if (ridx == nidx) {
		nidx = fread(rbuf, 1, 1 << 20, stdin);
		if (!nidx) return 0;
		ridx = 0;
	}
	return rbuf[ridx++];
}
inline int readInt() {
	int sum = 0;
	char now = read();
	bool flg = false;

	while (now <= 32) now = read();
	if (now == '-') flg = true, now = read();
	while (now >= 48) sum = sum * 10 + now - '0', now = read();

	return flg ? -sum : sum;
}


int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int m, n;
  m = readInt(), n = readInt();
  
  vector<int> bisk(n, 0);
  
  for(int i = 0; i < n; i++)
    bisk[i] = readInt();
    
  sort(all(bisk));
  
  ll l = 1;
  ll r = *max_element(all(bisk));
  
  ll res = -1;
  
  while(l <= r) {
    ll mid = l + (r - l) / 2;
    
    int count = 0;
    
    for(auto ptr = lower_bound(all(bisk), mid); ptr != bisk.end(); ptr++)
      count += *ptr / mid;

    
    if(count >= m) {
      res = max(res, mid);
      l = mid + 1;
    } else {
      
      r = mid - 1;
    }
  }
  
  if(res == -1) 
    cout << 0;
  else
    cout << res;
  
  return 0;
}
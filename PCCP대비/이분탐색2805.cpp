#include <bits/stdc++.h>
#define ll long long
using namespace std;

int h[1000000 + 10];

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, m, tH = -1;

    cin >> n >> m;

    for(int i = 0; i < n; i++) cin >> h[i];
    
    ll l = 0, r = 1000000000;

    while(l <= r) {
        ll mid = l + (r - l) / 2;
        ll s = 0;

        for(int i = 0; i < n; i++) if(h[i] - mid > 0) s += (h[i] - mid); 

        if(s >= m) l = mid + 1, tH = mid;
        else r = mid - 1;
        
    }

    cout << tH;

    return 0;
}
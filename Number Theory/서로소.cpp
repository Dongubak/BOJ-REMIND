//
// Created by 김혁중 on 2025. 2. 20..
//
#include <iostream>
#include <vector>
#include <cmath>
#define ll long long

using namespace std;

void era(vector<int>& prime, ll n) {
    for (ll i = 2; i * i <= n; i++) {
        if (prime[i] == 0) {
            for (ll j = i * i; j <= n; j += i) {
                prime[j] = 1;
            }
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, m;
    cin >> n;

    m = (int)sqrt(n);
    vector<int> prime(m + 2, 0);
    era(prime, m);

    ll res = n;

    for (ll i = 2; i * i <= n; i++) {
        if (prime[i] == 0 && n % i == 0) {
            while (n % i == 0) n = n / i;
            res -= res / i;
        }
    }

    if (n > 1) {
        res -= res / n;
    }

    cout << res;

    return 0;
}
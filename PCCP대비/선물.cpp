#include <iostream>
#include <iomanip>
#define ll long long

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    long double L, W, H;
    cin >> N >> L >> W >> H;

    long double l = 0.0, r = min(min(L, W), H);
    int cnt = 0;
    while (r - l > 1e-9 && cnt++ < 10000) {
        long double m = (l + r) / 2.0;
        ll count = (ll)(L / m);
        count *= (ll)(W / m);
        count *= (ll)(H / m);

        if (count >= N) { /// 더 크게 일단 l은 가능함
            l = m;
        } else {
            r = m;
        }
    }

    cout << fixed << setprecision(10) << l;

    return 0;
}
//
// Created by 김혁중 on 2025. 2. 19..
//
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#define ll long long
#define all(x) begin(x), end(x)

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;

    vector<int> A(n);
    set<int> s;

    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            s.insert(A[i] + A[j]);
        }
    }

    sort(all(A));

    for (int k = n - 1; k >= 0; k--) {
        for (int i = 0; i < k; i++) {
            if (s.count(A[k] - A[i])) {
                cout << A[k];
                return 0;
            }
        }
    }

    return 0;
}
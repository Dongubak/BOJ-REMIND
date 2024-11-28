
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int MAX = 500000;
ll arr[MAX + 1];
ll seg[4 * MAX];
ll lazy[4 * MAX];

// Lazy propagation으로 구간의 XOR 값을 적용
void propagate(int node, int start, int end) {
    if (lazy[node] != 0) {
        seg[node] ^= (lazy[node] * (end - start + 1));  // 현재 구간에 XOR 연산 반영
        
        if (start != end) {
            lazy[node * 2] ^= lazy[node];      // 왼쪽 자식에 XOR 연산 적용
            lazy[node * 2 + 1] ^= lazy[node];  // 오른쪽 자식에 XOR 연산 적용
        }
        lazy[node] = 0;
    }
}

// 세그먼트 트리 초기화
void build(int node, int start, int end) {
    if (start == end) {
        seg[node] = arr[start];
    } else {
        int mid = (start + end) / 2;
        build(node * 2, start, mid);
        build(node * 2 + 1, mid + 1, end);
        seg[node] = seg[node * 2] + seg[node * 2 + 1];
    }
}

// 구간 [l, r]에 대해 XOR 연산을 적용
void update_range(int node, int start, int end, int l, int r, int val) {
    propagate(node, start, end);
    
    if (r < start || end < l) {
        return;
    }
    
    if (l <= start && end <= r) {
        lazy[node] ^= val;  // lazy에 XOR 연산 반영
        propagate(node, start, end);
        return;
    }
    
    int mid = (start + end) / 2;
    update_range(node * 2, start, mid, l, r, val);
    update_range(node * 2 + 1, mid + 1, end, l, r, val);
    seg[node] = seg[node * 2] + seg[node * 2 + 1];
}

// 특정 인덱스의 값을 조회
ll query(int node, int start, int end, int idx) {
    propagate(node, start, end);
    
    if (start == end) {
        return seg[node];
    }
    
    int mid = (start + end) / 2;
    if (idx <= mid) {
        return query(node * 2, start, mid, idx);
    } else {
        return query(node * 2 + 1, mid + 1, end, idx);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    build(1, 0, n - 1);  // 세그먼트 트리 초기화
    
    cin >> m;
    
    for (int i = 0; i < m; i++) {
        int t;
        cin >> t;
        
        if (t == 1) {
            int a, b, c;
            cin >> a >> b >> c;
            update_range(1, 0, n - 1, a, b, c);
        } else if (t == 2) {
            int a;
            cin >> a;
            cout << query(1, 0, n - 1, a) << '\n';
        }
    }
    
    return 0;
}
#include <iostream>
#include <cmath>
#include <vector>
#include <climits>

#define WBUF_SIZE (1 << 20)
#define ll long long

using std::cin;
using std::cout;
using std::vector;

int N, M, K;
int currentReadIndex, lengthofBuffer;

char rbuf[WBUF_SIZE];
ll A[1'000'000 + 1];
ll sumT[2097152]; // 2^21로 설정하여 최대 크기 확보
ll lazy[2097152]; // lazy 배열

// 빠른 입출력을 위한 함수들
inline char read() {
    if (currentReadIndex == lengthofBuffer) { // 버퍼를 모두 읽은 경우
        lengthofBuffer = fread(rbuf, 1, WBUF_SIZE, stdin);
        if (!lengthofBuffer) return 0;
        currentReadIndex = 0;
    }
    return rbuf[currentReadIndex++];
}

inline ll readLongLong() {
    ll sum = 0;
    char now = read();
    bool flg = false;
    while (now <= 32) now = read();
    if (now == '-') {
        flg = true;
        now = read();
    }
    while (now >= 48) {
        sum = sum * 10 + now - '0';
        now = read();
    }
    return flg ? -sum : sum;
}

inline int readInt() {
    int sum = 0;
    char now = read();
    bool flg = false;
    while (now <= 32) now = read();
    if (now == '-') {
        flg = true;
        now = read();
    }
    while (now >= 48) {
        sum = sum * 10 + now - '0';
        now = read();
    }
    return flg ? -sum : sum;
}

// 세그먼트 트리 초기화
ll initSumT(int l, int r, int n) {
    if (l == r) {
        return sumT[n] = A[l];
    }
    int m = (l + r) / 2;
    return sumT[n] = initSumT(l, m, 2 * n) + initSumT(m + 1, r, 2 * n + 1);
}

void initSum() {
    initSumT(1, N, 1);
}

// Lazy Propagation을 위한 함수
void propagate(int nl, int nr, int n) {
    if (lazy[n] != 0) {
        sumT[n] += (nr - nl + 1) * lazy[n];
        if (nl != nr) {
            lazy[2 * n] += lazy[n];
            lazy[2 * n + 1] += lazy[n];
        }
        lazy[n] = 0;
    }
}

// 구간 합 쿼리
ll querySumT(int l, int r, int nl, int nr, int n) {
    propagate(nl, nr, n);
    if (nr < l || nl > r) {
        return 0;
    }
    if (l <= nl && nr <= r) {
        return sumT[n];
    }
    int m = (nl + nr) / 2;
    return querySumT(l, r, nl, m, 2 * n) + querySumT(l, r, m + 1, nr, 2 * n + 1);
}

ll querySum(int l, int r) {
    return querySumT(l, r, 1, N, 1);
}

// 구간 업데이트
void updateRangeT(int l, int r, ll diff, int nl, int nr, int n) {
    propagate(nl, nr, n);
    if (nr < l || nl > r) {
        return;
    }
    if (l <= nl && nr <= r) {
        lazy[n] += diff;
        propagate(nl, nr, n);
        return;
    }
    int m = (nl + nr) / 2;
    updateRangeT(l, r, diff, nl, m, 2 * n);
    updateRangeT(l, r, diff, m + 1, nr, 2 * n + 1);
    sumT[n] = sumT[2 * n] + sumT[2 * n + 1];
}

void updateRange(int l, int r, ll diff) {
    updateRangeT(l, r, diff, 1, N, 1);
}

int main(void) {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    N = readInt();

    for (int i = 1; i <= N; i++) {
        A[i] = readLongLong();
    }

    initSum();

    int a, b, c, q;
    ll d;
    q = readInt();
    for (int _ = 0; _ < q; _++) {
        a = readInt();
        if (a == 1) {
            b = readInt();
            c = readInt();
            d = readLongLong();
            updateRange(b, c, d);
        } else {
            b = readInt();
            cout << querySum(b, b) << '\n';
        }
    }

    return 0;
}

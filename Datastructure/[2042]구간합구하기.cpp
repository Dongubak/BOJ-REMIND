#include <iostream>
#include <vector>

#define ll long long

using std::cin;
using std::cout;
using std::vector;

ll segTree[4'000'000];
ll A[1'000'000 + 1];

int N, M, K;

ll initSegT(int l, int r, int n) {
   if(l == r) {
      return segTree[n] = A[l];
   }

   int m = (l + r) / 2;
   return segTree[n] = (initSegT(l, m, 2 * n) + initSegT(m + 1, r, 2 * n + 1));
}

void init(int N) { /// N은 A의 마지막 원소 인덱스
   initSegT(1, N, 1);
}

ll querySegT(int l, int r, int nl, int nr, int n) {
   if(nr < l || nl > r) {
      return 0;
   }

   if(nl >= l && nr <= r) {
      return segTree[n];
   }

   int m = (nl + nr) / 2;
   return querySegT(l, r, nl, m, 2 * n) + querySegT(l, r, m + 1, nr, 2 * n + 1);
}

ll query(int l, int r) {
   return querySegT(l, r, 1, N, 1);
}

ll updateSegT(int i, ll v, int nl, int nr, int n) {
   if(i < nl || nr < i) {
      return segTree[n];
   }

   if(nl == nr) {
      return segTree[n] = v;
   }
   int m = (nl + nr) / 2;
   return segTree[n] = updateSegT(i, v, nl, m, 2 * n) + updateSegT(i, v, m + 1, nr, 2 * n + 1);
}

void update(int i, ll v) {
   updateSegT(i, v, 1, N, 1);
}

int main(void) {
   std::ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   cin >> N >> M >> K;

   for(int i = 1; i <= N; i++) {
      cin >> A[i];
   }

   init(N);
   int a, b;
   ll c;
   for(int _ = 0; _ < M + K; _++) {
      cin >> a >> b >> c;

      if(a == 1) {
         update(b, c);
      } else {
         cout << query(b, c) << '\n';
      }
   }

   return 0;
}
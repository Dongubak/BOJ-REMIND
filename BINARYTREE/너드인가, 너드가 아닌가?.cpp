#include <bits/stdc++.h>
#define pp pair<int, int>

using namespace std;

bool isDominated(int r, int c, map<int, int>& C) { /// {r, c}가 점령당하는 가
  auto it = C.lower_bound(r);
  if(it == C.end()) return false;

  return c < it->second;
} 

void removeDominated(int r, int c, map<int, int>& C) {
  auto it = C.lower_bound(r);
  if(it == C.begin()) return; /// r보다 작은놈이 없으면 삭제할 게 없음
  --it; /// r보다 작은 놈중 가장 큰놈
  while(true) {
    if(it->second > c) break; /// 더 작은 놈이 없다는 것은 앞에서 이미 삭제한 거임
    if(it == C.begin()) {
      C.erase(it); /// 삭제할 거 발견하면 즉시 종료임
      break;
    } else {
      auto jt = it;
      --jt;

      C.erase(it);
      it = jt;
    }
  }
}

int registered(int r, int c, map<int, int>& C) {
  if(isDominated(r, c, C)) return C.size();
  removeDominated(r, c, C);
  C[r] = c;
  return C.size();
}

int main(void) {
  int T;
  cin >> T;

  while(T--) {
    int n, p, q;
    cin >> n;
    vector<int> P(n, 0), Q(n, 0);

    /// input
    for(int i = 0; i < n; i++) cin >> P[i] >> Q[i];
    
    map<int, int> C;
    int sum = 0;
    for(int i = 0; i < n; i++) {
      int nr = P[i], nc = Q[i];
      sum += registered(nr, nc, C);
    }

    cout << sum << '\n';
  }

  return 0;
}
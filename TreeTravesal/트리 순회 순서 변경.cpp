#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
using namespace std;

vector<int> pre;
vector<int> in;

vector<int> slice(const vector<int>& v, int a, int b) { /// a부터 b까지 서브 벡터 구함
  return vector<int>(v.begin() + a, v.begin() + b);
}

void sol(const vector<int>& preSub, const vector<int>& inSub) {
  // [i, j] root [k, l]
  int N = preSub.size();
  if(N == 0) return;
  
  int root = preSub[0]; /// 루트 노드
  int L = find(all(inSub), root) - inSub.begin(); 
  /// 위치이자 개수 - 1
  
  /// 중위 순회 배열에서는 처음 부터 rId 전과 rId 다음부터 끝까지로 전달함
  /// 전위 순회 배열에서는 처음을 제외하여 인덱스 + 1개

  sol(::slice(preSub, 1, L + 1), ::slice(inSub, 0, L));
  sol(::slice(preSub, L + 1, N), ::slice(inSub, L + 1, N));

  cout << root << ' ';
}

int main(void) {
  int T;
  cin >> T;

  while(T--) {
    int n;
    cin >> n;

    pre.resize(n, 0);
    in.resize(n, 0);

    for(int i = 0; i < n; i++) cin >> pre[i];
    for(int i = 0; i < n; i++) cin >> in[i];

    sol(pre, in);
  }


  return 0;
} 
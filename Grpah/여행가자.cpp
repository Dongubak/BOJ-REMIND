//
// Created by 김혁중 on 2025. 2. 19..
//
#include <iostream>
#include <vector>

using namespace std;

class disj {
  public:
  vector<int> A;
  disj(int n) {
    A.resize(n, 0);
    for(int i = 0; i < n; i++) {
      A[i] = i;
    }
  }

  int find(int n) {
    if(A[n] == n) return n;
    return A[n] = find(A[n]);
  }

  void merge(int n1, int n2) {
    int n1f = find(n1), n2f = find(n2);

    if(n1f != n2f) {
      A[n2f] = n1f;
    }
  }
};

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m, t;

  cin >> n >> m;

  disj dis(n);

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      cin >> t;
      if(t == 1) {
        dis.merge(i, j);
      }
    }
  }

  int cur, next;
  cin >> cur;

  int common = dis.find(cur - 1);
  for(int i = 0; i < m - 1; i++) {
    cin >> next;
    if(common != dis.find(next - 1)) {
      cout << "NO";
      return 0;
    }
  }

  cout << "YES";

  return 0;
}
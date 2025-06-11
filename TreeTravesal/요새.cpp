#include <bits/stdc++.h>

#define tt tuple<int, int, int>
using namespace std;

struct TreeNode {
  vector<TreeNode*> children;
  int value;
  int x;
  int y;
  int r;
};

double getLength(tt A, tt B) {
  auto [x1, y1, _] = A;
  auto [x2, y2, _] = B;

  return sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));
}

bool isIn(tt mayRoot, tt mayChild) {
  auto [x1, y1, r1] = mayRoot;
  auto [x2, y2, r2] = mayChild;
  
  int AB = getLength(mayRoot, mayChild);

  return (AB + r2 < r1);
}

int main(void) {
  int T;

  cin >> T;

  while(T--) {
    int n;
    cin >> n;

    int x, y, r;
    int m = 1;
    TreeNode* root = new TreeNode;
  
    for(int i = 0; i < n; i++) {
      cin >> x >> y >> r;


    }
  }

  return 0;
}
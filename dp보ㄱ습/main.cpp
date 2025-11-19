#include <bits/stdc++.h>

using namespace std;

int main(void)
{
  auto add = [&](int a, int b) -> int
  {
    return a + b;
  };

  int a, b;
  cin >> a >> b;

  cout << add(a, b);

  return 0;
}
#include <bits/stdc++.h>
#define ll long long
#define pp pair<int, int>

using namespace std;

int V, E, st, end;
vector<vector<pair<int, int>>> g;

void dijkstra() {
  priority_queue<pair<int, int>> pq; /// 큐에 넣을 당시 sht값과 그 정점을 pair로 저장
  vector<pp> sht(V + 1, pair<int, int>(INT_MAX, INT_MAX));
  sht[st] = {0, st}; /// i == st이면 종료하게 하면 될 듯
  pq.push({0, st});

  while(!pq.empty()) {
    pp cur = pq.top(); pq.pop();
    auto& [prevsht, cv] = cur;

    if(prevsht != sht[cv].first) continue; // 조사할 필요가 없음

    for(auto& [d, w]: g[cv])
        if(sht[d].first > sht[cv].first + w) {
          pq.emplace(sht[cv].first + w, d);
          sht[d].first = sht[cv].first + w;
          sht[d].second = cv; /// 이전 정점 기록
        }
  }

  stack<int> sta;
  
  int cur = ::end;

  while(cur != st) {
    sta.push(cur);
    cur = sht[cur].second;
  }
  sta.push(st);

  cout << sht[::end].first << '\n' << sta.size() << '\n';

  while(!sta.empty()) {
    cout << sta.top() << " ";
    sta.pop();
  }
}


int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> V >> E;
  int s, d, w;
  g.resize(V + 1, vector<pair<int, int>>()); // 1base index

  for(int i = 0; i < E; i++)
    cin >> s >> d >> w, g[s].emplace_back(d, w);
  
  cin >> st >> ::end;

  dijkstra();


  return 0;
}
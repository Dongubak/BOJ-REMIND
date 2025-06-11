#include <string>
#include <vector>
#include <map>
#include <queue>
#include <iostream>

using namespace std;
map<int, vector<int>> graph;
bool send[1000000 + 1]{false}, recv[1000000 + 1]{false};
int start;
void makeGraph(vector<vector<int>>& edges);
int bfs(int beginVertex);
vector<int> solution(vector<vector<int>> edges) {
   vector<int> answer;
   answer.resize(4, 0);

   /// lastVertex, start 알고있음
   makeGraph(edges);
   answer[0] = start;
   for(auto& startAdj: graph[start]) {
      int ret = bfs(startAdj);
      // cout << "ret : " << ret << '\n';
      answer[ret] += 1;
   }

   return answer;
}

void makeGraph(vector<vector<int>>& edges) {
   for(int i = 0; i < edges.size(); i++) {
      int src = edges[i][0], dst = edges[i][1];
      graph[src].emplace_back(dst);
      send[src] = true, recv[dst] = true;
   }

   for(auto& [key, _]: graph) {
      if(recv[key] == false) {
         start = key;
         break;
      }
   }
}

// 1.
/// 유예지점에서 끝나는가 8자
/// 유예지점이 없고 end == start 인가 도넛
/// 나머지 막대

// 2. vis없는 BFS돌리면
/// 제자리 돌아왔는 데 큐 빔 -> 도넛 (1)
/// 제저리 돌아왔는 데 큐 안 빔 -> 8자 (3)
/// 나머지 막대 (2)

/// 3. 인접 정점 2개 -> 8자
/// 1개 -> 끝까지 돌음 -> 도넛
/// 0개 -> 막대

/// 들어오는 정점 없는 놈
int bfs(int beginVertex) {
   queue<int> q;
   vector<bool> vis(1000000 + 1, false);

   q.emplace(beginVertex);
   
   // cout << beginVertex << '\n';
   
   while(!q.empty()) {
      int cur = q.front(); q.pop();

      if(graph[cur].size() == 2) {
         return 3;
      }

      if(graph[cur].size() == 0) {
         return 2;
      }

      for(auto& adj: graph[cur]) {
         if(vis[adj] == 0) {
            vis[adj] = 1;
            q.emplace(adj);   
         }
      }
   }

   return 1;
}
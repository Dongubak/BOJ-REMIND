#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <queue>
#define pp pair<int, int>

using namespace std;

void input(vector<vector<int>>& edges, vector<vector<int>>& graph, vector<int>& answer) {
    map<int, pp> sr;

    for(auto& edge: edges) {
      int src = edge[0], dst = edge[1];

      sr[src].first += 1;
      sr[dst].second += 1;

      graph[src].emplace_back(dst);
    }

    int start;

    int eight = 0, stick = 0;

    for(auto& [key, value]: sr) {
        if(value.first == 2 && value.second != 0) {
            eight += 1;
        }

        if(value.first == 0) {
          stick += 1;
        }

        if(value.second == 0 && value.first >= 2) {
          start = key;
        }
    }

    answer[0] = start;

    answer[2] = stick;
    answer[3] = eight;
    answer[1] = (int)graph[start].size() - (stick + eight);
}

int sol(vector<vector<int>>& graph, int st) {
    /// 도넛 : 1
    /// 막대 : 2
    /// 8자 : 3

    queue<int> q;
    vector<bool> vis(2000000 + 1, 0);
    q.emplace(st);
    vis[st] = 1;

    while(!q.empty()) {
      int cur = q.front(); q.pop();

      if((int)graph[cur].size() == 2) {
        return 3;
      }

      if((int)graph[cur].size() == 0) {
        return 2;
      }

      for(auto& dst: graph[cur]) {
        if(!vis[dst]) {
          q.emplace(dst);
          vis[dst] = 1;
        }
      }
    }

    return 1;
}

vector<int> solution(vector<vector<int>> edges) {
    vector<int> answer;
    answer.resize(4);

    vector<vector<int>> graph(2000000 + 1, vector<int>());

    input(edges, graph, answer);
//    int start = input(edges, graph);
//    answer[0] = start;
//
//    for(auto& adj: graph[start]) {
//      answer[sol(graph, adj)] += 1;
//    }
//
//    int sum = (int)graph[start].size();
//  /// 도넛 : 1
//  /// 막대 : 2
//  /// 8자 : 3
//    answer[1] = sum - (answer[2] + answer[3]);
//
////    answer[3] = sum - (answer[1] + answer[2]);

    return answer;
}
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int V, E;
int v1, v2; 
vector<vector<pair<ll, ll>>> g;

void dijkstra() {
   priority_queue<pair<ll, ll>> pq;
   vector<vector<ll>> sht(V + 1, vector<ll>(V + 1, INT_MAX));

   for(int i = 1; i <= V; i++) {
      if(i != v1 && i != v2 && i != 1) continue;
      sht[i][i] = 0LL;
      pq.push({0LL, i});

      while(!pq.empty()) {
         pair<ll, ll> cur = pq.top(); pq.pop();
         auto& [prevsht, cv] = cur;

         if(prevsht != sht[i][cv]) continue;

         for(auto& [d, w]: g[cv]) {
         	if(w == INT_MAX) continue;
            if(sht[i][d] > sht[i][cv] + w) {
               pq.emplace(sht[i][cv] + w, d);
               sht[i][d] = sht[i][cv] + w;
            }
		 }
         	
      }
   }

   ll l = sht[1][v1] + sht[v1][v2] + sht[v2][V];
   ll r = sht[1][v2] + sht[v2][v1] + sht[v1][V];
   
   if(l < r) { /// l < r
   		if(sht[1][v1] != INT_MAX && sht[v1][v2] != INT_MAX && sht[v2][V] != INT_MAX) {
   			cout << l;	
		} else if(sht[1][v2] != INT_MAX && sht[v2][v1] != INT_MAX && sht[v1][V] != INT_MAX){
			cout << r;
		} else {
			cout << -1;
		}
   } else { /// r < l
   		if(sht[1][v2] != INT_MAX && sht[v2][v1] != INT_MAX && sht[v1][V] != INT_MAX) {
   			cout << r;	
		} else if(sht[1][v1] != INT_MAX && sht[v1][v2] != INT_MAX && sht[v2][V] != INT_MAX){
			cout << l;
		} else {
			cout << -1;
		}
   }
   
   
}


int main(void) {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   cin >> V >> E;
   int s, d, w;
   g.resize(V + 1, vector<pair<ll, ll>>()); // 1base index

   for(int i = 0; i < E; i++) {
      cin >> s >> d >> w;
      g[s].emplace_back(d, w);
      g[d].emplace_back(s, w);
   }
      
   
   cin >> v1 >> v2;

   dijkstra();


   return 0;
}
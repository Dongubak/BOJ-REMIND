#include<iostream>
#include<vector>
#include<utility>
#include<queue>
#include<tuple>
#include<algorithm>

using namespace std;

int n,l,r,cnt,ret=0;   
int arr[54][54];
int visited[54][54];
int dx[4] = {-1,0,1,0};
int dy[4] = {0,-1,0,1};

vector<pair<int,int>> v1;

void check(int y, int x,vector<pair<int,int>> &v)
{
   for(int i=0; i<4;i++)
   {
      int ny = y + dy[i];
      int nx = x + dx[i];
      if(ny<0||nx<0||ny>=n||nx>=n||visited[ny][nx])continue;
      if(abs(arr[ny][nx]-arr[y][x])>=l && abs(arr[ny][nx]-arr[y][x])<=r)
      {  
         visited[ny][nx] =1;
         v.push_back({ny,nx});
         cnt += arr[ny][nx];
         check(ny,nx,v);
      }
   }
   return;
}


int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   cin>>n>>l>>r;
   for(int i =0; i<n;i++)
   {
      for(int j =0; j<n; j++)
      {
         cin>>arr[i][j];
      }
   }
   while(true)
   {
      bool flag = false;
      fill(&visited[0][0], &visited[0][0] +54*54,0);
      for(int i =0; i<n; i++)
      {
         for(int j=0; j<n; j++)
         {
            if(!visited[i][j])
            {
               v1.clear();
               visited[i][j] =1;
               v1.push_back({i,j});
               cnt = arr[i][j];
               check(i,j,v1);
               if(v1.size() == 1)continue;// 연합이 아니면 통과
               for(pair<int,int> a : v1)
               {
                  arr[a.first][a.second] = cnt/v1.size();
                  flag =true;
               }
            }
         }
      }
      if(!flag) break;// 한번이라도 연합 하면 falg가 true이기 때문에 while문이 멈추지않음
      ret++;
   }
   cout<<ret;
   return 0;   
}
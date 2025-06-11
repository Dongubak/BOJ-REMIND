#include <bits/stdc++.h>
using namespace std;

int N, L;
int road[100][100];

bool isValidPath(vector<int>& line) {
   vector<bool> used(N, false);
   
   for(int i = 0; i < N - 1; i++) {
      if(line[i] == line[i + 1]) continue;
      if(abs(line[i] - line[i + 1]) > 1) return false;
      if(line[i] < line[i + 1]) { // 앞이 큼
         for(int j = 0; j < L; j++) { /// i - j는 인덱싱이며 j = 0부터 시작하고 j < L이라면 L번 반복하는 것임
            // 범위를 벗어나거나, 이미 경사로가 있거나, 높이가 다르면 불가능
            if(i - j < 0 || used[i - j] || line[i - j] != line[i]) return false;
            used[i - j] = true;
         }
      } else {// 뒤가 큼
         // 경사로를 놓을 수 있는지 확인
         // for문에서 j = 1부터 시작하고 j <= L이라면 L번 반복하는 것임
         for(int j = 1; j <= L; j++) {
            // 범위를 벗어나거나, 이미 경사로가 있거나, 높이가 다르면 불가능
            if(i + j >= N || used[i + j] || line[i + j] != line[i + 1]) return false;
            used[i + j] = true;
         }
      }
   }
   return true;
}

int main() {
   cin >> N >> L;
   
   for(int i = 0; i < N; i++) {
      for(int j = 0; j < N; j++) {
         cin >> road[i][j];
      }
   }
   
   int count = 0;
   
   for(int i = 0; i < N; i++) {
      vector<int> line;
      for(int j = 0; j < N; j++) {
         line.push_back(road[i][j]);
      }
      if(isValidPath(line)) count++;
   }
   
   for(int j = 0; j < N; j++) {
      vector<int> line;
      for(int i = 0; i < N; i++) {
         line.push_back(road[i][j]);
      }
      if(isValidPath(line)) count++;
   }

   cout << count << '\n';
   return 0;
}
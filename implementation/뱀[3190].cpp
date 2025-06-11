#include <bits/stdc++.h>
#define pp pair<int, int>
using namespace std;

int N, K, L, board[100][100], count, curDir = 1;
pp tail, head;
char turn[10000 + 1];

int R[4] = {-1, 0, 1, 0};
int C[4] = {0, 1, 0, -1};

std::map<char, int> changeDir;

void input();
void turning(char d);
bool move(); 
void display() {
   cout << "-----------------" << '\n';
   cout << "count : " << ::count << '\n';

   for(int i = 0; i < N; i++) {
      for(int j = 0; j < N; j++) {
         cout << board[i][j] << " ";
      }
      cout << '\n';
   }
   cout << "-----------------" << '\n';
   cout << '\n';
}

int main(void) {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   input();   

   // display();
   while(move()) {
      if(turn[::count] > 'A') {
         turning(turn[::count]);
      }
      // display();
   }
   cout << ::count;

   return 0;
}

bool move() {
   ::count++;
   int nr = head.first + R[curDir], nc = head.second + C[curDir];

   if(nr >= 0 && nr < N && nc >= 0 && nc < N && (board[nr][nc] == 0 || board[nr][nc] == -1)) {
      if(board[nr][nc] == 0) {
         // cout << "tail : " << tail.first << " " << tail.second << '\n';
         
         board[nr][nc] = board[head.first][head.second] + 1;

         for(int i = 0; i < 4; i++) {
            int ntr = tail.first + R[i], ntc = tail.second + C[i];

            if(ntr >= 0 && ntr < N && ntc >= 0 && ntc < N && board[ntr][ntc] == board[tail.first][tail.second] + 1) {
               board[tail.first][tail.second] = 0;
               tail.first = ntr, tail.second = ntc;
               break;
            }
         }
         
      } else {
         board[nr][nc] = board[head.first][head.second] + 1;
      }

      head.first = nr, head.second = nc;

      return true;
   } else {
      // cout << "current : " << head.first << " " << head.second << "\n";
      // cout << "current dir : " << curDir << "\n";
      // cout << "board : " << board[nr][nc] << "\n";
      return false;
   }

}

void input() {
   cin >> N >> K;

   changeDir['D'] = 1;
   changeDir['L'] = -1;

   int t, v;

   for(int i = 0; i < K; i++) {
      cin >> t >> v;
      board[t - 1][v - 1] = -1;
   }

   board[0][0] = 1;

   cin >> L;

   
   for(int i = 0; i < L; i++) {
      cin >> t;
      cin >> turn[t];
   }
}

void turning(char d) {
   if(d == 'D') {
      curDir += 1;
      if(curDir == 4) {
         curDir = 0;
      }     
   } else {
      curDir -= 1;
      if(curDir < 0) {
         curDir = 3;
      }
   }
}
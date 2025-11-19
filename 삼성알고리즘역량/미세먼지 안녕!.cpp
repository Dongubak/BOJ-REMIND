#include <bits/stdc++.h>
#define pp pair<int, int>

using namespace std;

int R, C, T;
int mat[50][50];
int delMat[50][50]; // delta matrix
int rs1, cs1;
int rs2, cs2;
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, 1, -1};

int notOver(int r, int c)
{
  return r >= 0 && r < R &&
         c >= 0 && c < C &&
         mat[r][c] != -1;
}

int main(void)
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  bool sflag = false;
  cin >> R >> C >> T;
  for (int i = 0; i < R; i++)
  {
    for (int j = 0; j < C; j++)
    {
      cin >> mat[i][j];
      if (mat[i][j] == -1 && sflag == true)
      {
        rs2 = i, cs2 = j;
      }
      else if (mat[i][j] == -1 && sflag == false)
      {
        rs1 = i, rs2 = j;
        sflag = true;
      }
    }
  }

  while (T--)
  {
    memset(delMat, 0, sizeof(delMat));
    for (int i = 0; i < R; i++)
    {
      for (int j = 0; j < C; j++)
      {
        if (mat[i][j] <= 0)
          continue;

        int dirCount = 0;

        for (int k = 0; k < 4; k++)
        {
          int nr = i + dr[k];
          int nc = j + dc[k];

          if (notOver(nr, nc))
          {
            dirCount++;
            delMat[nr][nc] += mat[i][j] / 5;
          }
        }

        if (dirCount != 0)
        {
          delMat[i][j] -= dirCount * (mat[i][j] / 5);
        }
      }
    }

    for (int i = 0; i < R; i++)
    {
      for (int j = 0; j < C; j++)
      {
        mat[i][j] += delMat[i][j];
        if (
            !(i == rs1 && j == cs1) &&
            !(i == rs2 && j == cs2) &&
            mat[i][j] < 0)
          mat[i][j] = 0;
      }
    }

    // for (int i = 0; i < R; i++)
    // {
    //   for (int j = 0; j < C; j++)
    //   {
    //     cout << mat[i][j] << " ";
    //   }
    //   cout << '\n';
    // }
    // cout << '\n';

    for (int r = rs1, c = 0; r > 0; r--)
    {
      if (r == rs1)
      {
        mat[r - 1][c] = 0;
      }
      else
      {
        mat[r][c] = mat[r - 1][c];
        mat[r - 1][c] = 0;
      }
    }

    for (int r = rs2, c = 0; r < R; r++)
    {
      if (r == rs2)
      {
        mat[r + 1][c] = 0;
      }
      else
      {
        mat[r][c] = mat[r + 1][c];
        mat[r + 1][c] = 0;
      }
    }

    for (int c = 1; c < C; c++)
    {
      mat[0][c - 1] = mat[0][c];
      mat[0][c] = 0;

      mat[R - 1][c - 1] = mat[R - 1][c];
      mat[R - 1][c] = 0;
    }

    for (int r = 0; r < rs1; r++)
    {
      /// c = C - 1
      mat[r][C - 1] = mat[r + 1][C - 1];
      mat[r + 1][C - 1] = 0;
    }

    for (int r = R - 1; r > rs2; r--)
    {
      /// c = C - 1
      mat[r][C - 1] = mat[r - 1][C - 1];
      mat[r - 1][C - 1] = 0;
    }

    for (int c = C, r = rs1; c > 1; c--)
    {
      /// r = rs1
      mat[r][c] = mat[r][c - 1];
      mat[r][c - 1] = 0;
    }

    for (int c = C, r = rs2; c > 1; c--)
    {
      /// r = rs2
      mat[r][c] = mat[r][c - 1];
      mat[r][c - 1] = 0;
    }
  }

  // for (int i = 0; i < R; i++)
  // {
  //   for (int j = 0; j < C; j++)
  //   {
  //     cout << mat[i][j] << " ";
  //   }
  //   cout << '\n';
  // }
  // cout << '\n';

  int sum = 0;

  for (int i = 0; i < R; i++)
  {
    for (int j = 0; j < C; j++)
    {
      if (mat[i][j] == -1)
        continue;
      sum += mat[i][j];
    }
  }

  cout << sum;

  return 0;
}
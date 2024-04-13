#include "m.h"
#define n 50

int matrix[n][n] = {0};

bool isin(int x, int y)
{
    if(x >= 0 && x < n && y >= 0 && y < n)
    {
        return true;
    }
    return false;
}

int main()
{
  // 请在此输入您的代码
  int cnt = 0;
  int ans = 1;
  while(ans <= 2500)
  {
      for(int i = 0;i <= cnt;i++)
      {
        if(cnt % 2 == 1 && isin(i, cnt - i))
        {
            matrix[i][cnt - i] = ans;
            ans++;
        }
        if(cnt % 2 == 0 && isin(cnt - i, i))
        {
            matrix[cnt - i][i] = ans;
            ans++;
        }
      }
      cnt++;
  }
//   for(int i = 0;i < 20;i++)
//   {
//     for(int j = 0;j < 20;j++)
//     {
//         printf("%5d", matrix[i][j]);
//     }
//     cout << endl;
//   }
  cout << matrix[19][19] << endl;
  system("pause");
  return 0;
}